Create / write file contents
•	echo — write simple lines:
	echo "Z" > z
•	printf — precise bytes/newlines:
	printf 'Z\n' > z
•	cat — view/concatenate:
	cat z
•	tee — write and show:
	echo Z | tee z

Create special binary/content layouts
•	dd — write at specific offsets, create fixed-size files:
	printf '...' | dd of=ft_magic bs=1 seek=41 conv=notrunc  (puts data at byte 42)
•	xxd / hexdump — inspect hex and verify bytes:
	xxd ft_magic | sed -n '3p'
•	truncate — set file length:
	truncate -s 42 ft_magic

Permissions / ownership / links / timestamps
•	chmod — change mode:
	chmod 444 testShell00
•	chown / chgrp — change owner/group:
	chown user:group testShell00
•	ln / ln -s — hard link / symlink:
	ln test0 test5  (hard link)
	ln -s test0 test6 (symlink)
•	mkdir — create directories:
	mkdir test0
•	touch — set timestamps:
	touch -t 202306012342 testShell00  (YYYYMMDDhhmm)
•	install — create file/dir with owner/mode/timestamp in one go (handy):
	install -m 0555 -o user -g group /dev/null test1

Listing / formatting / sorting (for ls outputs / midLS)
•	ls — listing in many forms:
	ls -l (long list)
	ls -p (append / to dirs)
	ls -1t or ls -1U (sort by time/creation if supported)
•	stat — show birth/ctime/mtime (if FS supports birth time):
	stat -c '%W %n' *
•	find — find files recursively and act on them:
	find . -name '*~' -o -name '#*#' -print -delete  (one-liner that finds and deletes backups)
•	sort / awk / paste / tr — format output (e.g., comma-separated list)

Archive / submission
•	tar — create tarball:
	tar -cf testShell00.tar testShell00
	tar -cf exo2.tar *

Kerberos
•	kinit — get ticket
•	klist — list tickets:
	klist > klist.txt

Git-related
•	git log — last 5 commit ids:
	git log --pretty=format:'%H' -n 5
•	git ls-files — list ignored / untracked:
	git ls-files --others -i --exclude-standard  (lists ignored files)

File-type magic / file command
•	file — check file type using magic files:
	file -m ft_magic somefile
•	file’s magic format editing + ft_magic creation: use dd/printf to create test files and add an entry in a custom magic file to detect the “42 at byte 42” pattern.

Utilities for scripting and formatting
•	awk, sed, cut, xargs, wc — parse and transform ls/find/git output (e.g., compgen -c | wc -l you used earlier)
•	bash / sh — run your scripts:
	bash git_commit.sh | cat -e

Remove / move / copy
•	rm, mv, cp — standard file ops (set perms/links after copy if needed)

Groups for a user (FT_USER) — commands that work
•	id -nG "$FT_USER" — prints group names separated by spaces; convert to commas:
	id -nG "$FT_USER" | tr ' ' ','
•	alternative (reads /etc/group and /etc/passwd to include primary group reliably):
	getent passwd "$FT_USER" | cut -d: -f4  # primary GID
	getent group | awk -F: -v u="$FT_USER" '$4 ~ ("(^|,)"u"(,|$)") {print $1}'

	then combine results and paste -sd, -.

Git tasks
•	last 5 commit ids: git log --pretty=format:'%H' -n 5
•	ignored files: git ls-files --others -i --exclude-standard

Archiving / submission
•	tar -cf testShell00.tar testShell00
•	tar -cf exo2.tar *

Kerberos
•	kinit — get ticket
•	klist — list tickets: klist > klist.txt

Display every-other line of ls -l
•	starting from first: ls -l | sed -n '1~2p'
•	starting from second: ls -l | sed -n '2~2p'

MAC addresses (network interfaces)
•	ip link show and awk:
	ip link show | awk '/link\/ether/{print $2}'
•	or with ifconfig -a (older systems): ifconfig -a | awk '/ether/{print $2}'

file magic / creating ft_magic
•	file -m ft_magic targetfile — use a custom magic file
•	create the magic file with printf/echo/dd creating bytes at offset 41 (42nd byte).
Tools used: printf, dd, truncate, file, xxd, hexdump to verify bytes.

