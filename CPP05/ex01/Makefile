# Nom de l'exécutable
NAME = Bureaucrat

# Compilateur et options de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources et objets
SRCS = Bureaucrat.cpp main.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(NAME)

# Construction de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJS)

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)

# Règle pour tout recompiler
re: fclean all

# Indication de cible fictive
.PHONY: all clean fclean re