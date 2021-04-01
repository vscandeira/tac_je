############################# Makefile ##########################

# Comandos
COMPILER = g++
RMDIR = rm -rf
RM = rm

#Flags
DEP_FLAGS = -M -MT $@ -MT $(BIN_PATH)/$(*F).o -MP -MF $@
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

FLAGS = -std=c++11 -Wall -pedantic -Wextra -Wno-unused-parameter -Werror=init-self
DFLAGS = -ggdb -00 -DEBUG
RFLAGS = -03 -mtune=native


#Caminhos
INC_PATHS = -I$(INC_PATH) $(addprefix -I, $(SDL_INC_PATH))
INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

#Lista de arquivos
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(INC_PATH)/*.h)
FILE_NAMES = $(sort $(notdir $(CPP_FILES:.cpp=)) $(notdir $(INC_FILES:.h=)) )
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

folders:
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)

#Arquivo
EXEC=JOGO

#regra geral
all: $(EXEC)

#Gera o executável:
$(EXEC): $(OBJ_FILES)
	$(COMPILER) -o $@ $^ $(LINK_PATH) $(LIBS) $(FLAGS)

# Gera os arquivos objetos
$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | folders
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

# Gera os arquivos de dependencia
$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | folders
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

#$(EXEC): $(OBJ_FILES)
#	$(COMPILER) -o $@ $^ $(LINK_PATH) $(LIBS)

#$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp
#	@mkdir -p $(DEP_PATH) $(BIN_PATH)
#	$(COMPILER) $(DEP_FLAGS) -c -o $@ $< $(INC_PATH) $(FLAGS) -include $(DEP_FILES)

.SECONDEXPANSION:
	.include $$(DEP_FILES)

clean:
	$(RMDIR) $(DEP_PATH)
	$(RMDIR) $(BIN_PATH)
	$(RM) $(EXEC)



