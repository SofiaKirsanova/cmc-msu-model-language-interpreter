type_of_lex.o: type_of_lex.cpp type_of_lex.h
scanner.o: scanner.cpp scanner.h lex.h table_ident.h ident.h \
 type_of_lex.h table_str.h
table_label.o: table_label.cpp table_label.h
lex.o: lex.cpp lex.h table_ident.h ident.h type_of_lex.h table_str.h
ident.o: ident.cpp ident.h type_of_lex.h
executer.o: executer.cpp executer.h parser.h table_label.h poliz.h \
 scanner.h lex.h table_ident.h ident.h type_of_lex.h table_str.h
interpretator.o: interpretator.cpp interpretator.h executer.h parser.h \
 table_label.h poliz.h scanner.h lex.h table_ident.h ident.h \
 type_of_lex.h table_str.h
parser.o: parser.cpp parser.h table_label.h poliz.h scanner.h lex.h \
 table_ident.h ident.h type_of_lex.h table_str.h
table_str.o: table_str.cpp table_str.h
poliz.o: poliz.cpp poliz.h scanner.h lex.h table_ident.h ident.h \
 type_of_lex.h table_str.h
table_ident.o: table_ident.cpp table_ident.h ident.h type_of_lex.h
main.o: main.cpp table_label.h interpretator.h executer.h parser.h \
 poliz.h scanner.h lex.h table_ident.h ident.h type_of_lex.h table_str.h \
 table_label.cpp ident.cpp table_ident.cpp table_str.cpp lex.cpp \
 scanner.cpp poliz.cpp parser.cpp interpretator.cpp
