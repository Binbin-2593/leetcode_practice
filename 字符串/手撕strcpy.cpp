/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-24 17:33:27
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-24 19:47:25
 * @FilePath: /.leetcode/字符串/手撕strcopy.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// char *strcpy(char *a,char *b){
// 	if(!a||!b){
// 		cout<<"字符串为空"<<endl;
// 		return NULL;
// 	}
	
// 	char *d=b;
// 	int size = strlen(a)+1;
// 	if(d>a&&d<a+size){     //第一种情况，自我赋值时，这里实现了俩个指针的错位，防止内存重叠 
// 	 	d=d+size-1;
// 	 	a=a+size-1;
// 	 	while(size--){
// 	 		*d--=*a--;
// 		}
// 	}else{
// 	 	while(size--)     //非自我赋值时候 
// 	 	*d++=*a++;
// 	} 
// }
//把 b 所指向的字符串复制到 a,返回新a
char* Strcpy(char* a, const char* b){
	if (!a||!b) { // 空指针判断
		cout<<"字符串为空"<<endl;
		return nullptr;
	}
	char* p = a;// 记录好指针头部不变
	while (*b != '\0') {
		*(p++) = *(b++);
	}
	return a;
}


