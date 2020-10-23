 검색
 선형 검색
 while(1)
 if i == n
	return -1
 if (a[i] == key;
	return i;

 for (i = 1; i < n; i++)
 if ( a[i] == key
	return i;
 else return -1

 보초 선형검색
 a[n] = key를 추가 a[n-1]까지 배열이 되어있기 때문에 메모리 참조에서 +1를 늘려줘야함
while(1)
 if (a[i] == key)
	break;
	i++
return i == n ? -1 : i

 이진 검색
 pl 왼쪽부터 검색 pr 오른쪽부터 검색 pc는 중간의 값. 인덱스 이기때문에 pl = 0 pr = n-1의 값.
 do{
 pc = pl+pr / 2
 if (a[i] == key)
	return pc;
 else if (a[pc] < key)
	pl = pc +1
 else
	pr = pc - 1;
 } while (pl <= pr)
 return -1

 bsearch
int int_cmp(const int* a, const int* b) 
오름차순임, 내림차순은 리턴값을 반대로 하면 됨.
{
	if (*a < *b)
		return -1;
	else if (*a > * b)
		return 1;
	else
		return 0;
}

 bsearch 함수
 (int (*)const(void *, const void *))int _cmp

     if (*a < *b)
         return 1
     else if (*a > * b) 
         return -1
     else
         return 0
      