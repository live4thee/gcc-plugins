static int g_dummy = 0;

int foo(int a);

int main(void)
{
    return foo(g_dummy);
}

int foo(int a)
{
	int b = 1;
	return a + b;
}
