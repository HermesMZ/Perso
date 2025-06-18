#!/bin/bash

USERNAME="mzimeris"
HOSTNAME="mzimeris42"
SSH_PORT="4242"

echo "--- Mise à jour et installation des outils de base ---"
apt update
apt -y upgrade
apt -y install sudo vim ufw ssh

echo "--- Configuration de l'utilisateur ---"

echo "Ajout du répertoire /usr/sbin au PATH de l'utilisateur root"
echo 'export PATH="$PATH:/usr/sbin"' >> /root/.bashrc
source /root/.bashrc

echo "Le répertoire /usr/sbin a été ajouté au PATH de '$USERNAME' et root."

echo "--- Configuration de l'expiration du mot de passe root ---"
chage -M 30 root
chage -m 2 root
chage -W 7 root
chage -M 30 $USERNAME
chage -m 2 $USERNAME
chage -W 7 $USERNAME

echo "--- Configuration de l'expiration des mots de passe (login.defs) ---"
sed -i 's/^PASS_MAX_DAYS\s*99999/PASS_MAX_DAYS\t30/g' /etc/login.defs
sed -i 's/^PASS_MIN_DAYS\s*0/PASS_MIN_DAYS\t2/g' /etc/login.defs
sed -i 's/^PASS_WARN_AGE\s*7/PASS_WARN_AGE\t7/g' /etc/login.defs

echo "--- Configuration de sudo ---"
cat <<EOF | sudo tee /etc/sudoers.d/zz-defaults
Defaults        passwd_tries=3
Defaults        badpass_message="Il s'agirait de le retenir ce mot de passe !"
Defaults        log_input
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        log_output
Defaults        iolog_dir="/var/log/sudo"
Defaults        requiretty
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
EOF
mkdir -p /var/log/sudo
echo "Configuration de sudo terminée."

echo "--- Configuration de SSH (changement de port et désactivation de root)"
sed -i 's/^#Port 22/Port '"$SSH_PORT"'/g' /etc/ssh/sshd_config
bash -c "echo 'PermitRootLogin no' >> /etc/ssh/sshd_config"

echo "--- Redémarrage du service SSH ---"
systemctl restart ssh

echo "--- Configuration du pare-feu UFW ---"
ufw enable
ufw allow "$SSH_PORT"/tcp
ufw default deny incoming
ufw default allow outgoing
ufw enable

echo "--- Configuration de la politique des mots de passe (PAM) ---"
sed -i '/^password.*pam_unix\.so/i password\trequisite\tpam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root' /etc/pam.d/common-password

echo "Ajout de l'utilisateur '$USERNAME' aux groupes sudo & user42"
groupadd user42
usermod -aG user42 $USERNAME
usermod -aG sudo $USERNAME

echo "--- Configuration de la tâche cron pour monitoring.sh (root) ---"
MONITORING_SCRIPT="/home/$USERNAME/monitoring.sh"
chmod +x $MONITORING_SCRIPT
CRON_LINE="*/10 * * * * /bin/bash \"$MONITORING_SCRIPT\""
echo "$CRON_LINE" | crontab -u "root" -

echo "--- Script de configuration terminé ---"
