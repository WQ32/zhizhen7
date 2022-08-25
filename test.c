#include <stdio.h>

//用冒泡排序函数实现多个类型的排序

void Swap(char* buf1,char* buf2,int width)
{
	int k = 0;
	for (k = 0; k < width; k++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void bubble_sort(void* base,int sz,int width,int(*cmp)(void* e1,void* e2))
{
	int i = 0;
	// 趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的对数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素的比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
void test5()
{
	int arr[10] = { 2,4,3,7,1,0,9,8,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]),cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

struct Stu
{
	char name[10];
	int age;
};
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test6()
{
	struct Stu s[3] = { {"Zhangsan",25},{"Lisi",46},{"Wangwu",18} };
	int sz1 = sizeof(s) / sizeof(s[0]);
	// bubble_sort(s, sz1, sizeof(s[0]), cmp_stu_by_age);
	bubble_sort(s, sz1, sizeof(s[0]), cmp_stu_by_name);
	int l = 0;
	for (l = 0; l < sz1; l++)
	{
		printf("%s ", s[l]);
	}
}
int main()
{
	test5();
	printf("\n");
	test6();
	return 0;
}