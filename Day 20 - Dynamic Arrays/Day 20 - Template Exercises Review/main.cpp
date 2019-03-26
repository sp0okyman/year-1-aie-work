#include <iostream>

// create a generic data-type with typename keyword, we'll call it t_template
//template<typename t_template>
// in lieu of normal data types such as int, float, double, etc., t_template is used to be a template for future data insertion
//t_template Add(t_template a, t_template b)
//{
//	return a + b;
//}

template<typename t_minimum>
t_minimum minimum(t_minimum a, t_minimum b)
{
	if ( a > b ){ return b; }
	else { return a; }
}

template<typename t_maximum>
t_maximum maximum(t_maximum a, t_maximum b)
{
	if (a < b) { return a; }
	else { return b; }
}

template<typename t_clamp>
t_clamp clamp(t_clamp a, t_clamp b)
{

}

int main()
{
	// integer of int type is the sum of Add, our template function, which returns the sum of a + b, or 5 and 7, of which are both integers
	//int integer = Add(5, 7);
	// f_float of float type is the sum of Add, which returns the sum of a + b, 5.0f and 7.0f, both of which are floats
	//float f_float = Add(5.0f, 7.0f);
	// can explicitly state what data type to return with <whateverthefuck>
	//int integer_two = Add<int>(5, 7);
	//float f_float_two = Add<float>(5.0f, 7.0f);
	// if multiple data types are in parameters, you MUST explicitly state what data-type should be used
	//int r1 = Add(5, 7.0f); <--- shit doesn't work
	//int r2 = Add<int>(5, 7.0f); <--- shit works, the return value would be an int, and therefore will not accept anything after the decimal place



	return 0;
}