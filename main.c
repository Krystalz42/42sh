void test(int i){dprintf(2, "%d\n", i);}

int main(){int i = -1; while (++i < 32)signal(i, test); int buff = 0; read(0, &buff, 8); write(1, &buff, 8); return (buff);}
