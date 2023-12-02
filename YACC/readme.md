# RUN YACC PROGRAM
---
- In terminal type **flex filename.l**
- After generating lex.yy.c file type **yacc -d filename.y**
- Once it generate y.tab.c file type **gcc lex.yy.c y.tab.c -ll**
- Then type **./a.out**