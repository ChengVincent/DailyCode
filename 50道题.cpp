#include<iostream>
#include<CString>
#include<assert.h>
#include<stdarg.h>
using namespace std;

/**********************
<1>输出hello world
**********************/
void Test1()
{
    cout << "Hello World!!" << endl;
}
/**********************
<2>输出1到100的和
**********************/
void Test2()
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    cout << "the 1 to 100 sum is" << sum;
}
/**********************
<3>9*9乘法表
**********************/
void Test3()
{
    int column, row;
    for (row = 1; row <= 9; row++)
    {
        for (column = row; column <= 9; column++)
        {
            cout << row << "*" << column << "=" << row*column << "  ";
        }
        cout << endl;
    }
}
/*********************
<4>两个值整数较大
**********************/
void Test4()
{
    int i, j;
    cout << "请输入两个整数";
    cin >> i >> j;
    if (i > j)
    {
        cout << "最大的是" << i;
    }
    else
    {
        cout << "最大的是" << j;
    }
}
/*************************
<5>求十个数中最大值
**************************/
void Test5()
{
    cout << "请输入十个数"<<endl;
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }
    int max = array[0];
    for (int j = 1; j < 10; j++)
    {
        if (array[j]>max)
        {
            max = array[j];
        }
    }
    cout << "最大数是" << max << endl;
}
/************************
<6>1到100之间的素数
************************/
void Test6()
{
    bool prime = false;
    for (int i = 2; i < 100; i++)
    {
        for (int j = 2; j < i; j++)
        {
            prime = true;
            if (i%j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            cout << i << " ";
        }
    }
}
/**********************
<7&8>求两个整数的最大公约数,最小公倍数
***********************/
int gcd(int a, int b)
{
    if (a < b)return gcd(b, a);
    else if (b == 0)return a;
    else return gcd(b, a%b);
}
int lun(int a, int b)
{
    return a*b / gcd(a, b);
}
void Test7()
{
    cout << "请输入两个整数" << endl;
    int i, j;
    cin >> i >> j;
    cout << "最大公约数是" << gcd(i, j) << endl;
    cout << "最小公倍数是" << lun(i, j) << endl;

}
/**********************
<9&10>交换两个值
**********************/
void exchange(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void Test8()
{
    cout << "请输入两个数" << endl;
    int i, j;
    cin >> i >> j;
    cout << "原来的值为" << i << " " << j << endl;
    exchange(i, j);
    cout << "第一次交换后值为" << i << " " << j << endl;
    i = i + j;
    j = i - j;
    i = i - j;
    cout << "第二次交换后值为" << i << " " << j << endl;
}
/************************
<9>1234可以组成多少个互不重复的三位数
*************************/
void Test9()
{
    int i, j, k, count=0;
    for (i = 1; i < 5;i++)
    {
        for (j = 1; j < 5; j++)
        {
            for (k = 1; k < 5; k++)
            {
                if (i != j&&j != k&&i != k)
                {
                    cout << i << j << k << endl;
                    count++;
                }
            }
        }
    }
    cout << "The count is" << count;
}
/************************
<10>两千年以前所有闰年和闰年个数
*************************/
void Test10()
{
    int count = 0;
    for (int i = 1; i < 2000; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            cout << i << endl;
            count++;
        }
    }
    cout << "The count of leap year is" << count;
}
/**********************************
<11>编写程序求2/1，3/2，5/3.。。。数列前二十项之和
**********************************/
void Test11()
{
    float i=1.0, j=2.0, sum=0;
    for (int k = 0; k < 20; k++)
    {
        sum += j / i;
        j = i + j;
        i = j - i;
    }
    cout << sum;
}
/********************
<12>求a，aa，aaa，aaaa.。。。前n项之和
********************/
void Test12()
{
    int a, n, sum = 0;
    int m = 1;
    cout << "please input a and n" << endl;
    cin >> a >> n;
    for (int i = 0; i < n; i++)
    {
        m *= 10;
        sum += m;
    }
    sum = (sum - n)*a / 9;
    cout << sum;
}
/******************************
<13>球高度为100，反弹高度为下落一半，第十次时反弹高度，已经过路程
*******************************/
void Test13()
{
    float nowHigh=100, total=100;
    for (int i = 0; i < 10; i++)
    {
        nowHigh *= 0.5;
        total += (2*nowHigh);
    }
    cout << "反弹高度为" << nowHigh << endl;
    cout << "走过路程为" << total << endl;
}
/*******************************
<14>一堆桃每次吃一半又一，第十次时剩一，求原数
********************************/
void Test14()
{
    int i, total = 0, last = 1;
    for (i = 0; i < 9; i++)
    {
        last = (last + 1) * 2;
        total += last;
    }
    cout << "原来有桃" << total;
}
/**********************************
<15>1-1/2+1/3-1/4+1/5.....-1/100的值
***********************************/
void  Test15()
{
    int i;
    float sum = 0;
    for (i = 1; i < 100; i++)
    {
        if (i % 2)
        {
            sum = sum + (float)(1.0 / i);
        }
        else
        {
            sum = sum - (float)(1.0 / i);
        }
    }
    cout << "总数为" << sum;
}
/***********************************
<16>一到二十的阶乘和
*************************************/
void Test16()
{
    int sum = 0;
    for (int i = 1; i <= 20; i++)
    {
        int mul = 1;
        for (int j = 1; j <= i; j++)
        {
            mul *= j;
        }
        sum += mul;
    }
    cout << "总数是" << sum;
}
/**********************************
<17>判断回文数
***********************************/
void Test17()
{
    char a[20];
    cout << "请输入一个数字" << endl;
    gets_s(a);
    for (size_t i = 0; i <( strlen(a) / 2); i++)
    {
        if (a[i] == a[strlen(a) - i - 1])
        {
            continue;
        }
        else
        {
            cout << "不是回文数" << endl;
            return;
        }
    }
    cout << "是回文数" << endl;
}
/**********************************
<18>判断回文字符串
************************************/
void Test18()
{
    char a[20];
    cout << "请输入一个字符串" << endl;
    gets_s(a);
    for (size_t i = 0; i <(strlen(a) / 2); i++)
    {
        if (a[i] == a[strlen(a) - i - 1])
        {
            continue;
        }
        else
        {
            cout << "不是回文字符串" << endl;
            return;
        }
    }
    cout << "是回文字符串" << endl;
}
/***********************************
<19>输出一个三成三矩阵对角线之和
**************************************/
void Test19()
{
    cout << "请输入一个三成三矩阵" << endl;
    int array[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3;j++)
        cin >> array[i][j];
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += array[i][i];
        sum += array[i][2 - i];
    }
    sum -= array[1][1];
    cout << "总数是" << sum;
}
/*************************************
<20>逆序一个整形数组
*************************************/
void Test20()
{
    cout << "请输入一个整形数组，以CTRL+Z结尾" << endl;
    int count = 0;
    int array[20] = { 0 };
    while ((cin >> array[count++]));//当有文件结束符时结束循环
    for (int i = 0; i < (count - 1) / 2; i++)
    {
        int temp = array[i];
        array[i] = array[count - 2 - i];
        array[count - 2 - i] = temp;
    }
    cout << "逆序后是:";
    for (int i = 0; i < count - 1; i++)
    {
        cout << array[i] << " ";
    }
}
/************************************
<21>冒泡排序整形数组
**************************************/
void Test21()
{
    cout << "请输入一个整形数组，以CTRL+Z结尾" << endl;
    int count = 0;
    int array[20] = { 0 };
    while ((cin >> array[count++]));//当有文件结束符时结束循环
    for (int i = 0; i < count - 2; i++)
    {
        for (int j = 0; j < count - 2 - i; j++)
        {
            if (array[j] < array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    cout << "冒泡排序的结果是：";
    for (int i = 0; i < count - 1; i++)
    {
        cout << array[i] << " ";
    }
}
/**************************************
<22>多个字符串排序，相当于strcmp
*****************************************/
void Test22()
{
    cout << "有三个字符串“bit-tech”“world”“hello”进行排序" << endl;
    char array1[] = "hello";
    char array2[] = "bit-tech";
    char array3[] = "world";
    if (strcmp(array1, array2)==1)
    {
        if (strcmp(array1, array3)==1)
        {
            if (strcmp(array2, array3)==1)
                cout << array1 << " " << array2 << " " << array3;
            else
                cout << array1 << " " << array3 << " " << array2;
        }
        else
        {
            cout << array3 << " " << array1 << " " << array2;
        }
    }
    else
    {
        if (strcmp(array2, array3)==1)

        {
            if (strcmp(array1, array3)==1)
                cout << array2 << " " << array1 << " " << array3;
            else
                cout << array2 << " " << array3 << " " << array1;
        }
        else
            cout << array3 << " " << array2 << " " << array1;
    }
}
/****************************************
<23>递归法求Fibonacci
****************************************/
int Fibonacci(int i)
{
    if (i == 1)
    {
        return 1;
    }
    else if (i==2)
    {
        return 1;
    }
    else
    {
        return (Fibonacci(i - 1) + Fibonacci(i - 2));
    }
}
void Test23()
{
    int n;
    cout << "要计算第几项fibonacci：";
    cin >> n;
    cout << "the answer is " << Fibonacci(n);
}
/***************************************
<24>非递归求Fibonacci
*****************************************/
void Test24()
{
    int n;
    cout << "要计算第几项Fibonacci：";
    cin >> n;
    int f1 = 1, f2 = 1;
    while(n - 2 > 0)
    {
        f2 = f2 + f1;
        f1 = f2 - f1;
        n--;
    }
    cout << "计算结果是" <<f2;
}
/*****************************************
<25>编写strlen
*****************************************/
void Test25()
{
    char array[20];
    cout << "请输入一个字符串"<<endl;
    gets_s(array);
    int n = 0;
    while (array[n] != '\0')
    {
        n++;
    }
    cout << "字符串长度为" << n;
}
/**************************************
<26>不创建临时变量求一个字符串长度
*****************************************/
int GetStrLen(char *p)
{
    if ((*p) == '\0')
    {
        return 0;
    }
    else return (GetStrLen(p + 1) + 1);
}
void Test26()
{
    char array[20];
    cout << "请输人一个字符串" << endl;
    gets_s(array);
    cout << "字符串长度为"<<GetStrLen(array);
}
/**************************************
<27>选择排序对一个整形数组排序
****************************************/
void Test27()
{
    cout << "请输入一个整形数组，以CTRL+Z结尾" << endl;
    int count = 0;
    int array[20] = { 0 };
    while ((cin >> array[count++]));//当有文件结束符时结束循环
    for (int i = 0; i < count - 2; i++)
    {
        for (int j = i+1; j < count - 1; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    cout << "选择排序的结果是：";
    for (int i = 0; i < count - 1; i++)
    {
        cout << array[i] << " ";
    }
}
/*****************************************
<28>求一个数二进制序列中一的个数
*****************************************/
void Test28()
{
    int n,count=0;
    cout << "请输入一个数"<<endl;
    cin >> n;
    while (n)
    {
        n &= n - 1;
        count++;
    }
    cout << "其二进制中有1：" << count << "个";
}
/**************************************
<29>判断大小端
****************************************/
union A
{
    int a;
    char b;
};
void Test29()
{
    A temp;
    temp.a = 1;
     if (temp.b == 1)
        cout << "大端模式";
    else
        cout << "小端模式";
}
/****************************************
<30>一到一百中9出现的次数
***************************************/
void Test30()
{
    int count = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i / 10 == 9)
            count++;
        if (i % 10 == 9)
            count++;
    }
    cout << "一到一百中九出现次数：" << count;
}
/**********************************
<31>接收一个整数输出每位数字
**********************************/
void Test31()
{
    char array[20];
    int count = 0;
    cout << "请输入一个整数" << endl;
    gets_s(array);
    while (array[count]!='\0')
    {
        cout << array[count] << " ";
        count++;
    }
}
/******************************
<32>在某个字符串中查找一个字符第一次出现的位置，没有返回NULL
****************************/
void Test32()
{
    char array[20];
    cout << "请输入字符串" << endl;
    gets_s(array);
    char ch;
    cout << "请输入要查找的字符" << endl;
    cin >> ch;
    int count = 0;
    while (array[count] != '\0')
    {
        if (array[count] == ch)
        {
            cout << "第" << count + 1 << "我们所要找的" << endl;
            return;
        }
        count++;
    }
    cout << "没有找到" << endl;
}
/*****************************
<33>从一个字符串中提取一个字符字串
*******************************/
int SubStr(char *dst, char *src, int start, int len)
{
    assert(NULL!=src||NULL!=dst);
    if (start > (int )strlen(src) || start + len > (int)strlen(src))
    {
        cout << "复制越界，无法完成" << endl;
        return 0;
    }
    int count = 0;
    while (count != start)
    {
        if (*src == '\0')
        {
            return 0;
        }
        src++;
        count++;
    }
    for (int i = 0; i < len; i++)
    {
        if (*src == '\0')
        {
            return i;
        }
        *dst++ = *src++;
    }
    *dst = '\0';
    return len;
}
void Test33()
{
    char str[20];
    char substr[20];
    int start;
    int len;
    cout << "请输入一个字符串" << endl;
    cin >> str;
    cout << "请输入复制起始位置" << endl;
    cin >> start;
    cout << "请输入复制长度" << endl;
    cin >> len;
    if (SubStr(substr, str, start, len) != 0)
    {
        cout << substr;
    }
}
/*********************************
<34>把一串字符中的小写变大写，其余不变
*********************************/
void Test34()
{
    char array[20];
    cout << "请输入一个字符串" << endl;
    cin >> array;
    int count=0;
    while (array[count] != '\0')
    {
        if (array[count] >= 'a'&&array[count] <= 'z')
            array[count] += ('Z'-'z');
        count++;
    }
    cout << "转换后的字符串为" << array;
}
/**********************************
<35>对应编码a-z，b-y，z-A
**********************************/
void Test35()
{
    char array[20];
    cout << "请输入一个字符数组" << endl;
    cin >> array;
    int count = 0;
    while (array[count] != '\0')
    {
        array[count] -= ((array[count] - 'a') * 2 + 7);
        count++;
    }
    cout << array;
}
/**********************************
<36>strcpy
************************************/
void MyStrcpy(char *dst, char *src)
{
    assert(NULL != dst || NULL != src);
    while (*src != '\0')
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}
void Test36()
{
    char src[20];
    char dst[20];
    cout << "请输入一个字符串" << endl;
    cin >> src;
    MyStrcpy(dst, src);
    cout << "复制后的字符串为" << dst;
}
/**************************************
<37>strcat
*************************************/
char* MyStrcat(char* dest, char *src)
{
    char *MyDest = dest;
    assert(NULL != dest || NULL != src);
    if (20 < (strlen(dest) + strlen(src)+1))
    {
        cout << "目的字符串缓冲区不足" << endl;
        return src;
    }
    while (*MyDest)
    {
        MyDest++;
    }
    while (*src)
    {
        *MyDest = *src;
        MyDest++;
        src++;
    }
    *MyDest = '\0';
    return dest;
}
void Test37()
{
    char dest[20];
    char src[20];
    cout << "请输入原字符串" << endl;
    cin >> src;
    cout << "请输入目的字符串" << endl;
    cin >> dest;
    cout << "链接后的字符串是" << MyStrcat(dest, src);
}
/*************************************
<38>strcmp
**************************************/
int MyStrcmp(const char* str1,const char* str2)
{
    while (1)
    {
        if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;
        else
        {
            if (*str1 == '\0')
            {
                return 0;
            }
            str1++;
            str2++;
        }
    }
}
void Test38()
{
    char str1[20];
    char str2[20];
    cout << "请输入字符串1" << endl;
    cin >> str1;
    cout << "请输入字符串2" << endl;
    cin >> str2;
    cout << "str1>str2输出1，小于输出-1，相等为0" << endl << MyStrcmp(str1, str2);
}
/**************************************
<39>memcpy
*************************************/
void MyMemcpy(void* s1, const void* s2, size_t n)
{
     unsigned char *su1, *su2;
    su1 = ( unsigned char*)s1;
    su2 = ( unsigned char*)s2;
    while (n)
    {
        *su1 ++= *su2++;
        n--;
    }
}
/*************************************
<40>memmove
**************************************/
void* MyMemmove(void *s1, const void*s2, size_t n)
{
    char *sc1;
    const char *sc2;
    sc1 = (char *)s1;
    sc2 = (const char*)s2;
    if (sc2 < sc1&&sc1 < sc2 + n)
        for (sc1 += n, sc2 += n; 0 < n; --n)
            *--sc1 = *--sc2;
    else
    for (; 0 < n; --n)
    {
        *sc1++ = *sc2++;
    }
    return(s1);
}
/*************************************
<41>memset
***************************************/
void* MyMemset(void *s, int c, size_t n)
{
    const unsigned char* uc = (const unsigned char*)c;
    unsigned char *su;
    for (su = (unsigned char*)s; 0 < n; ++su, --n)
    {
        *su = *(const unsigned char *)uc;
    }
    return (void *)s;
}
/****************************************
<42>字符串转换成数字
***************************************/
double StrToNum(char *str)
{
    int n=0;
    double m=0;
    while (*str)
    {
        if (*str == '.')
        {
            break;
        }
        n *= 10;
        n += (*str - '0');
        str++;
    }
    while (*(++str)!='\0');
    str--;
    while (*str != '.')
    {
        m *=0.1;
        m += (0.1*(*str - '0'));
        str--;
    }
    return (double)(m + n);
}
void Test42()
{
    char array[20];
    cout << "请输入一个字符串" << endl;
    cin >> array;
    cout << "数字是" <<StrToNum(array)<<endl;
}
/**************************************
<43>一元一瓶汽水，两空瓶换瓶汽水，20元喝多少
**************************************/
void Test43()
{
    int money;
    cout << "请输入你的钱数" << endl;
    cin >> money;
    int drinkNum = money,empty=money;
    while (empty > 1)
    {
        drinkNum += empty / 2;
        empty = empty % 2 + empty / 2;
    }
    cout << "可以喝" << drinkNum << endl;
}
/**************************************
<44>可变参数列表求平均值
***************************************/
int Average(unsigned int n, ...) 
{
    int sum = 0;
    int m = n;
    va_list args; 
    va_start(args, n);  
    while (n>0)
    {
        sum += va_arg(args, int);
        n--;
    }
    va_end(args);
    return sum/m;
}
void Test44()
{
    cout << Average(3,1,2,3) << endl;
}
/****************************************
<45>student a am i转换为正常语句
*****************************************/
char* Trans(char* dest,char* src)
{
    char *srcHead = src;
    char *des = dest;
    while (*(++src) != '\0');
    int count = 0;
    src--;
    while (1)
    {
        while (*src!=' '&&src!=srcHead-1)
        {
            src--;
            count++;
        }
        src++;
        for (int i = 0; i < count; i++)
        {
            *dest = src[i];
            dest++;
        }
        if (src == srcHead)
        {
            *dest = '\0';
            return des;
        }
        count = 0;
        src = src - 2;
        *dest++ = ' ';
    }
}
void Test45()
{
    char src[20];
    char dest[20];
    cout << "请输入一个字符串" << endl;
    gets_s(src);
    cout << "转换后的字符串是"<<Trans(dest, src);

}

/****************************************
<46>把一个数的二进制反转后的值求出来
****************************************/
void Test46()
{
    unsigned int value;
    unsigned int rValue = 0;
    cout << "请输入一个数" << endl;
    cin >> value;
    for (int i = 0; i < 32; i++)
    {
        if (value& 1)
        {
            rValue += 1;
        }
        if (i != 31)
        {
            rValue <<= 1;
            value >>= 1;
        }
    }
    cout << "反转之后的值为" <<rValue<< endl;
}
int main()
{
    Test42();
    return 0;
}

