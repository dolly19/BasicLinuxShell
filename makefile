all : shell rm cat mkdir ls date

mkdir : mkdir.c
	cc -o mkdir mkdir.c
	
date : date.c
	cc -o date date.c

shell : shell.c
	cc -o shell shell.c

cat : cat.c
	cc -o cat cat.c

ls : ls.c
	cc -o ls ls.c
	
rm : rm.c
	cc -o rm rm.c
