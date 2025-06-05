FT_LINE1=7
FT_LINE2=15

grep -v '#' /etc/passwd | cut -d: -f1 | awk 'NR%2==1' | rev | sort -r | awk -v debut="$FT_LINE1" -v fin="$FT_LINE2" 'NR>=debut && NR<=fin {printf "%s%s", $0, (NR==fin ? "." : ", ")}'
