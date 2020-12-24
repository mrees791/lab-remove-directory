all:
	gcc app.c remove_dir/remove_dir.h remove_dir/remove_dir.c -o app
clean:
	rm app
