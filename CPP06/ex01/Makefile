
# Nom du programme à générer
TARGET = serializer_test

# Compilateur à utiliser
CXX = c++
# Options de compilation
CXXFLAGS = -std=c++98 -Wall

# Liste des fichiers sources
SRCS = main.cpp Serializer.cpp
# Liste des fichiers objets à générer à partir des sources
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut : construire le programme cible
all: $(TARGET)

# Règle pour construire le programme cible
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Règle pour les fichiers objets à partir des fichiers sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)
