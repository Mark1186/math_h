CC=gcc
C_FLAGS=-Wall -Werror -Wextra
L_FLAGS=-lpthread -lcheck -pthread -lrt -lm -lsubunit
G_FLAGS=--coverage
STD=-std=c11
FILES=functions/*.c tests/*.c
H_FILES=tests/*.h s21_math.h
TEST_FILES=tests/s21_test_
FUNC_FILES=functions/*.c
NAME=s21_test_
LIB_NAME=s21_math.a
FILES_OUT=*.o

all: s21_math.a

test: s21_math.a
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)abs.c -L. $(LIB_NAME) -o $(NAME)abs $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)acos.c -L. $(LIB_NAME) -o $(NAME)acos $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)asin.c -L. $(LIB_NAME) -o $(NAME)asin $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)atan.c -L. $(LIB_NAME) -o $(NAME)atan $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)ceil.c -L. $(LIB_NAME) -o $(NAME)ceil $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)cos.c -L. $(LIB_NAME) -o $(NAME)cos $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)exp.c -L. $(LIB_NAME) -o $(NAME)exp $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)fabs.c -L. $(LIB_NAME) -o $(NAME)fabs $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)floor.c -L. $(LIB_NAME) -o $(NAME)floor $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)fmod.c -L. $(LIB_NAME) -o $(NAME)fmod $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)log.c -L. $(LIB_NAME) -o $(NAME)log $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)pow.c -L. $(LIB_NAME) -o $(NAME)pow $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)sin.c -L. $(LIB_NAME) -o $(NAME)sin $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)sqrt.c -L. $(LIB_NAME) -o $(NAME)sqrt $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)tan.c -L. $(LIB_NAME) -o $(NAME)tan $(L_FLAGS) $(G_FLAGS)
	make run_test
run_test:
	./$(NAME)abs
	./$(NAME)acos
	./$(NAME)asin
	./$(NAME)atan
	./$(NAME)ceil
	./$(NAME)cos
	./$(NAME)exp
	./$(NAME)fabs
	./$(NAME)floor
	./$(NAME)fmod
	./$(NAME)log
	./$(NAME)pow
	./$(NAME)sin
	./$(NAME)sqrt
	./$(NAME)tan
s21_math.a:
	$(CC) $(STD) $(C_FLAGS) -c $(FUNC_FILES)
	make create_lib
	rm -rf *.o
create_lib:
	ar rcs $(LIB_NAME) $(FILES_OUT)
gcov_report: clean test
	lcov -t "s21_math" -o s21_math.info -c -d .
	genhtml -o report s21_math.info
clang_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(FILES) $(H_FILES)
clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(FILES) $(H_FILES)
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf report
	rm -rf s21_t*
