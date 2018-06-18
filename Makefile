NAME = avm 

SRCS =	srcs/*.cpp

HEADERDIR = includes

BUILDDIR = build

FLAGS = -Wall -Werror -Wextra -iquote

COMPILER = clang++

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(BUILDDIR)/$(NAME)

$(BUILDDIR)/$(NAME):
	if [ ! -d "$(BUILDDIR)" ]; then \
		mkdir $(BUILDDIR); \
	fi 

	@echo "$(OK)----------   Compile $(NAME)    ----------$(NONE)"
	@$(COMPILER) -o $(BUILDDIR)/$(NAME) $(SRCS) $(FLAGS)$(HEADERDIR)
	@echo "$(OK)----------     Success     ----------$(NONE)\n"

clean:
	@echo "$(WARN)----------    Clean $(NAME)     ----------$(NONE)"
	@rm -f $(BUILDDIR)/$(NAME)
	@echo "removed $(BUILDDIR)/$(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

fclean:
	@echo "$(WARN)----------    FClean $(NAME)    ----------$(NONE)"
	@rm -f $(BUILDDIR)/$(NAME)
	@echo "removed $(BUILDDIR)/$(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

re: fclean all

run:
	./$(BUILDDIR)/$(NAME)
