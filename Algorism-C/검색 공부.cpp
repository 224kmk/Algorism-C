 �˻�
 ���� �˻�
 while(1)
 if i == n
	return -1
 if (a[i] == key;
	return i;

 for (i = 1; i < n; i++)
 if ( a[i] == key
	return i;
 else return -1

 ���� �����˻�
 a[n] = key�� �߰� a[n-1]���� �迭�� �Ǿ��ֱ� ������ �޸� �������� +1�� �÷������
while(1)
 if (a[i] == key)
	break;
	i++
return i == n ? -1 : i

 ���� �˻�
 pl ���ʺ��� �˻� pr �����ʺ��� �˻� pc�� �߰��� ��. �ε��� �̱⶧���� pl = 0 pr = n-1�� ��.
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
����������, ���������� ���ϰ��� �ݴ�� �ϸ� ��.
{
	if (*a < *b)
		return -1;
	else if (*a > * b)
		return 1;
	else
		return 0;
}

 bsearch �Լ�
 (int (*)const(void *, const void *))int _cmp

     if (*a < *b)
         return 1
     else if (*a > * b) 
         return -1
     else
         return 0
      