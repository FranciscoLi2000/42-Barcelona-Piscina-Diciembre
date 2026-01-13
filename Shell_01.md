Meaning of #?/bin/sh
•	The correct interpreter directive (shebang) is #! /bin/sh (no space usually: #!/bin/sh). The kernel recognizes #! at the start of an executable script and uses the following path as the interpreter.
•	#?/bin/sh is not a shebang. A leading # makes the line a comment in shell scripts, so #?/bin/sh is just a comment string (character ? has no special meaning there).
	→ If you want the system to run the script with /bin/sh, use #!/bin/sh as the first two characters of the file.

Base conversions / weird custom alphabets
•	bc — general base math (but limited to 0-9A-Z digits)
•	awk — custom base mapping possible in one-liners
•	python / perl — easiest for arbitrary custom digit alphabets and converters (map custom symbols → numeric values, convert, output in desired alphabet). Example approach: python -c '...translate & convert...'

Misc utilities that are useful in pipelines
•	head, tail, wc, xargs, sort, uniq, nl (number lines), printf, date, env

•	groups separated by commas: (simple works on typical systems)
	id -nG "$FT_USER" | tr ' ' ','

•	find .sh files but print names without .sh:
	find . -type f -name '*.sh' -printf '%f\n' | sed 's/\.sh$//'

•	count regular files + directories (include .):
	find . \( -type f -o -type d \) | wc -l

•	MAC addresses:
	ip link show | awk '/link\/ether/ {print $2}'

•	clean command — show and delete *~ and #*# only (one command):
	find . \( -name '*~' -o -name '#*#' \) -print -delete

•	every other line from ls -l, starting from first:
	ls -l | sed -n '1~2p'

•	passwd pipeline building blocks (see order earlier):
cat /etc/passwd \
| sed '/^#/d' \
| sed -n '2~2p' \
| cut -d: -f1 \
| rev \
| sort -r \
| sed -n "${FT_LINE1},${FT_LINE2}p" \
| paste -sd ', ' - \
| sed 's/$/./'

•	git last 5 commit ids:
	git log --pretty=format:'%H' -n 5

•	git ignored files:
	git ls-files --others -i --exclude-standard

