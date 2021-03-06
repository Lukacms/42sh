##
## EPITECH PROJECT, 2021
## 42sh
## File description:
## Makefile
##

SPECIAL_VARIABLE =	src/analyse_command/mods/special_variables/handler/

SRC	=	src/launch.c	\
		src/prompt/display_prompt.c	\
		src/env/destroy_list/free_list.c	\
		src/env/manipulate_linked_list/find_variable_by_name.c	\
		src/env/manipulate_linked_list/replace_variable_value.c	\
		src/env/manipulate_linked_list/add_node_for_setenv.c	\
		src/env/destroy_list/free_specific_node.c	\
		src/analyse_command/cmd_loop/analyse_cmd.c	\
		src/analyse_command/get_cmd.c	\
		src/destroy/destroy_shell.c	\
		src/job_control/my_pgid.c	\
		src/job_control/my_pid.c	\
		src/job_control/shell_fd.c	\
		src/job_control/fgpid.c	\

SRC_PARSE	=	src/analyse_command/parsing/parse_cmd.c	\
		src/analyse_command/parsing/separate_cmd.c	\
		src/analyse_command/parsing/array_quoted.c	\
		src/analyse_command/parsing/split/add_split_node.c	\
		src/analyse_command/parsing/split/info_split_node.c	\
		src/analyse_command/parsing/split/free_split_node.c	\
		src/analyse_command/parsing/split/red/info_red_node.c	\
		src/analyse_command/parsing/split/red/free_red_list.c	\
		src/analyse_command/parsing/split/red/add_redirect_node.c	\
		src/analyse_command/parsing/split/red/pipe/add_pipe_node.c	\
		src/analyse_command/parsing/split/red/pipe/free_pipe_list.c	\
		src/analyse_command/parsing/split/red/pipe/magic/add_magic.c	\
		src/analyse_command/parsing/split/red/pipe/info_in_pipe_node.c	\
		src/analyse_command/parsing/split/red/pipe/array_without_magic.c	\
		src/analyse_command/parsing/split/red/pipe/magic/free_magic_list.c	\

SRC_CMD	=	src/analyse_command/cmd_loop/split_cmd.c	\
		src/analyse_command/cmd_loop/red_cmd.c	\
		src/analyse_command/cmd_loop/pipe_cmd.c	\
		src/analyse_command/cmd_loop/pipe/loop_pipe.c	\
		src/analyse_command/cmd_loop/pipe/simple_cmd.c	\
		src/analyse_command/cmd_loop/red/double_left_redirect.c	\
		src/analyse_command/cmd_loop/red/double_right_redirect.c	\
		src/analyse_command/cmd_loop/red/left_redirect.c	\
		src/analyse_command/cmd_loop/red/right_redirect.c	\
		src/analyse_command/cmd_loop/red/beheads_node.c	\
		src/analyse_command/cmd_loop/red/concate_nodes.c	\
		src/analyse_command/cmd_loop/pipe/execute_pipe.c	\
		src/analyse_command/cmd_loop/red/check_errors.c	\
		src/history/update_history.c	\
		src/analyse_command/cmd_loop/pipe/magic/magic_loop.c	\
		src/job_control/check_jobs.c	\
		src/job_control/manage_jobs.c	\

SRC_ALIASES	=	src/aliases/add_node.c	\
		src/aliases/find_alias_by_name.c	\
		src/aliases/replace_alias.c	\
		src/aliases/print_alias_value.c	\
		src/aliases/analyse_aliases.c	\
		src/aliases/delete/delete_specific_alias.c	\
		src/aliases/delete/delete_all_aliases.c	\

SRC_INIT	=	src/prerequisite/create_shell.c	\
		src/prerequisite/init_history.c	\
		src/prerequisite/init_job.c	\
		src/env/create_env_linked_list/add_node.c	\
		src/env/create_env_linked_list/create_env_list.c	\

SRC_BUILTINS	=	src/analyse_command/commands_handler/command_cd.c	\
		src/analyse_command/commands_handler/command_env.c	\
		src/analyse_command/commands_handler/command_exit.c	\
		src/analyse_command/commands_handler/command_setenv.c	\
		src/analyse_command/commands_handler/command_unsetenv.c	\
		src/analyse_command/commands_handler/command_alias.c	\
		src/analyse_command/commands_handler/command_unalias.c	\
		src/analyse_command/commands_handler/command_history.c	\
		src/analyse_command/commands_handler/command_jobs.c	\
		src/analyse_command/commands_handler/command_fg.c	\

SRC_EXEC	=	src/analyse_command/launch_binaries/execute/env_to_array.c	\
		src/analyse_command/launch_binaries/paths_list/destroy_paths.c	\
		src/analyse_command/launch_binaries/paths_list/create_path_list.c	\
		src/analyse_command/launch_binaries/paths_list/add_path_node.c	\
		src/analyse_command/launch_binaries/execute/execute_command.c	\
		src/analyse_command/launch_binaries/execute/search_in_paths.c	\
		src/analyse_command/launch_binaries/execute/execute_binary.c	\
		src/analyse_command/launch_binaries/execute/error.c	\

SRC_KERNEL	=	src/kernel/terminal.c	\
		src/analyse_command/mods/analyse_char.c	\
		src/analyse_command/getnextline.c	\
		src/analyse_command/mods/special_char_handler/delete_handler.c	\
		src/analyse_command/mods/special_char_handler/ctrl_l_handler.c	\
		src/analyse_command/mods/special_char_handler/key_up_handler.c	\
		src/analyse_command/mods/special_char_handler/key_left_handler.c	\
		src/analyse_command/mods/special_char_handler/key_down_handler.c	\
		src/analyse_command/mods/special_char_handler/key_right_handler.c	\

SRC_MODS	=	src/analyse_command/mods/inhibitor.c	\
		src/analyse_command/mods/apply_mods.c	\
		src/analyse_command/mods/globbing.c	\
		src/analyse_command/mods/clean_globbing.c	\
		src/analyse_command/mods/special_variables/special_variables.c	\
		$(addprefix $(SPECIAL_VARIABLE), dollard_handler.c)	\
		$(addprefix $(SPECIAL_VARIABLE), underscore_handler.c)	\
		$(addprefix $(SPECIAL_VARIABLE), exclamation_handler.c)	\
		$(addprefix $(SPECIAL_VARIABLE), hashtag_handler.c)	\
		$(addprefix $(SPECIAL_VARIABLE), zero_handler.c)	\
		$(addprefix $(SPECIAL_VARIABLE), interogation_handler.c)	\

OBJ	=	$(SRC:.c=.o) $(SRC_PARSE:.c=.o) $(SRC_CMD:.c=.o) $(SRC_ALIASES:.c=.o)
OBJ	+= $(SRC_INIT:.c=.o) $(SRC_BUILTINS:.c=.o) $(SRC_EXEC:.c=.o)
OBJ	+= $(SRC_KERNEL:.c=.o) $(SRC_MODS:.c=.o)

SRC_MAIN	=	src/main.c

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC_TESTS1	=	tests/minishell1/tests_env.c	\
		tests/minishell1/test_setenv.c	\
		tests/minishell1/tests_errors_for_builtsin.c	\
		tests/minishell1/test_exit.c	\
		tests/minishell1/test_prompt.c	\
		tests/minishell1/tests_cd.c	\
		tests/minishell1/tests_side_functions.c	\
		tests/minishell1/tests_get_commands.c	\
		tests/minishell1/tests_execute_binary.c	\
		tests/minishell1/tests_env_functions.c

SRC_TESTS2	=	tests/minishell2/parsing_errors.c	\
		tests/minishell2/tests_parsing.c	\
		tests/minishell2/integration_test.c	\

SRC_TESTS42	=	tests/42sh/tests_aliases.c	\
		tests/42sh/magic_tests.c	\
		tests/42sh/test_42_integration.c	\

OBJ_TESTS	=	$(SRC_TESTS1:.c=.o) $(SRC_TESTS2:.c=.o) $(SRC_TESTS42:.c=.o)

NAME_TESTS	=	unit_test

NAME	=	42sh

LIBMY	=	lib/libmy.a

CFLAGS	=	-W -Wall -Wextra -Wpedantic

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib

LDLIBS	=	-lmy -lncurses

CC	=	gcc

all:	$(NAME)
.PHONY:	all

$(LIBMY):
	@make -C lib/my

$(NAME):	$(LIBMY) $(OBJ_MAIN) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(LDLIBS)

debug: fclean
debug: CFLAGS += -g
debug: $(NAME)
.PHONY:	debug

clean:
	@find -name "*.o" -delete
	@make clean -C lib/my
	@find -name "*.gcno" -delete
	@find -name "*.gcda" -delete
.PHONY:	clean

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_TESTS)
	@make fclean -C lib/my
.PHONY:	fclean

tests_run:	CPPFLAGS	+=	--coverage
tests_run:	CFLAGS	+=	-fprofile-arcs -ftest-coverage
tests_run:	LDLIBS	+=	-lcriterion -lgcov -lmy
tests_run:	fclean $(OBJ) $(OBJ_TESTS) $(LIBMY)
	gcc -o $(NAME_TESTS) $(OBJ) $(OBJ_TESTS) $(LDFLAGS) $(LDLIBS)
	-./$(NAME_TESTS)
.PHONY:	tests_run

coverage:
	gcovr --exclude tests
	gcovr --exclude tests --branches
.PHONY:	coverage

re:	fclean all clean
.PHONY:	re
