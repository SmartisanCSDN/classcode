//线性表抽象类linearList
template<class T>
class linearList
{
    public:
    	virtual ~linearList(){};
        virtual bool empty() const=0;
               //当线性表为空时显示true
        virtual int size() const=0;
               //返回线性表元素个数
        virtual T& get(int theIndex) const=0;
               //返回索引为theIndex的元素
        virtual int indexOf(const T& theElement) const=0;
               //返回元素theElement第一次出现时的索引
        virtual void erase(int theIndex)=0;
               //删除索引为theIndex的元素
        virtual void insert(int theIndex,const T& theElement)=0;
               //把theElement插入线性表索引为theIndex的位置上
        virtual void output(ostream& out) const=0;
               //把线性表插入输出流out
};

//用数组描述的线性表arrayList
template<class T>
class arrayList:public linearList<T>
{
	private:
		T* element[];  //存储线性表元素的一维数组
		int arrayLength;  //一维数组的容量
		int listSize;  //线性表s的元素个数
		void checkIndex(int theIndex) cont;
			   //若索引theIndex无效，则抛出异常
	public:
		//构造函数
		arrayList(int initialCapacity=10);
		//复制构造函数
		arrayList(const arrayList<T>&);
		//析构函数
		~arrayList()
		{
			delete [] element;
		}
		bool empty() const
		{
			return listSize==0;
		}
		int size() const
		{
			return listSize;
		}
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex,const T& theElement);
		void output(ostream& out) const;
		int capacity() const  //返回数组element当前的长度
		{
			return arrayLength;
		}
}
void arrayList<T>::checkIndex(int theIndex) const
{
	if(theIndex<0||theIndex>=listSize)
	{
		ostringstream s;
		s<<"index="<<theIndex<<"size="<<listSize;
		throw illegalIndex(s.str());
	}
}
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity<1)
	{
		ostringstream s;
		s<<"Iitial capacity ="<<initialCapacity<<"Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength=initialCapacity;
	element=new T[arrayLength];
	listSize=0;
}
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength=theList.arrayLength;
	listSize=theList.listSize;
	element=new T[arrayLength];
	copy(theList.element,theList.element+listSize,element);
}
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex=(int)(find(element,element+listSize,theElement)-element);
	if(theIndex==listSize)
		return -1;
	else
		return theIndex;
}
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element+theIndex+1,element+listSize,element+theIndex);
	element[--listSize].~T();
}
void arrayList<T>::insert(int theIndex,const T& theElement)
{
	if(theIndex<0||theIndex>listSize)
	{
		ostringstream s;
		s<<"index="<<theIndex<<"size="<<listSize;
		throw illegalIndex(s.str());
	}
	if(listSize==arrayLength)
	{
		changeLength1D(element,arrayLength,2*arrayLength);
		arrayLength*=2;
	}
	copy_backword(element+theIndex,element+listSize,element+listSize+1);
	element[theIndex]=theElement;
	listSize++;
}
void arrayList<T>::output(ostream& out) const
{
	copy(element,element+listSize,ostream_iterator(out," "));
}
ostream& operator<<(ostream& out,const arrayList<T>& x)
{
	x.output(out);
	return out;
}