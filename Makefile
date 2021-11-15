all: clean
	idf.py build

clean:
	idf.py fullclean

