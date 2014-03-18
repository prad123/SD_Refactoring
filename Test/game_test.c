#include <stdlib.h>
#include "seatest/seatest.h"
#include "../Src/game.h"

board_type* g_board;
const int rows = 6;
const int cols = 7;

void test_valid_moves(){
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	makeMove(g_board, 4);
	assert_true(validMove(g_board,4)==1);
}

void test_fixture_one(){
	test_fixture_start();
	run_test(test_valid_moves);
	test_fixture_end();
}

void all_tests(){
	test_fixture_one();
}

void test_setup(){
	g_board = createBoard(rows, cols);
}

void test_teardown(){
	free(g_board);
}

int main(int argc, char** argv){
	suite_setup(test_setup);
	suite_teardown(test_teardown);
	run_tests(all_tests);
}
