#include <stdio.h>
#include <math.h>

struct complex_struct {
	double x, y;
};

double real_part(struct complex_struct z)
{
	return z.x;
}

double img_part(struct complex_struct z)
{
	return z.y;
}

double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}
struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

void print_complex_struct(struct complex_struct z)
{
    printf("real_part-----> %f\n",real_part(z));
    printf("img_part-----> %f\n",img_part(z));
    printf("magnitude-----> %f\n",magnitude(z));
    printf("angle-----> %f\n\n",angle(z));
}
int main(void)
{
    struct complex_struct z1={1.0,2.0};
    struct complex_struct z2={3.0,4.0};
    print_complex_struct(add_complex(z1,z2));
    print_complex_struct(sub_complex(z1,z2));
    print_complex_struct(mul_complex(z1,z2));
    print_complex_struct(div_complex(z1,z2));

    return 0;
}
