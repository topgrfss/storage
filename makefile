# Универсальный Makefile для C++ проекта
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -I./include
TARGET = storage

# Автоматический поиск всех .cpp файлов
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Автоматический поиск заголовков для зависимостей
HEADERS = $(wildcard include/*.h)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Автоматическое правило для .cpp -> .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Автоматическая генерация зависимостей
DEPFLAGS = -MMD -MP
CXXFLAGS += $(DEPFLAGS)
DEPFILES = $(SOURCES:.cpp=.d)
-include $(DEPFILES)

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPFILES)

debug: CXXFLAGS += -g -O0
debug: clean all

release: CXXFLAGS += -O3 -DNDEBUG
release: clean all

.PHONY: all clean run debug release
