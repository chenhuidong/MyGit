all:lexical_cast stringize variant variant_to_long_double
lexical_cast:
	g++ test_lexical_cast.cpp -olexical_cast
stringize:
	g++ stringize.cpp -ostringize
variant:
	g++ test_variant.cpp -ovariant
variant_to_long_double:
	g++ variant_to_long_double.cpp -ovariant_to_long_double
.PHONY:clean
clean:
	rm lexical_cast stringize variant variant_to_long_double