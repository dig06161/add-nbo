TARGET=add-nbo

all: $(TARGET)

$(TARGET): main.cpp
	gcc main.cpp -o add-nbo

clean:
	rm -f add-nbo

