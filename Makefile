build:
	jbuilder build

run: build
	./_build/install/default/bin/reason-native-starter-bin

test: 
	echo "No tests yet" && exit 0

clean:
	rm -rf _build *.install

.PHONY: build test
