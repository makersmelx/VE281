# Mid review

## Slide 2

### Big-Oh

#### 1. The big-oh

$$
\begin{array}{l}{\text { Definition: A non-negatively valued function, } T(n), \text { is in the }} \\ {\text { set } O(f(n)) \text { if there exist two positive constants } C \text { and } n_{0}} \\ {\text { such that } T(n) \leq c f(n) \text { for all } n>n_{0} \text { . }}\end{array}
$$

#### 2. A sufficient condition of Big-Oh
$$
\text { If } \lim _{n \rightarrow \infty} \frac{f(n)}{g(n)}=c<\infty, \text { then } f(n) \text { is } O(g(n))
$$

#### 3. Rules

![image-20191016112001335](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112001335.png)

![image-20191016112009715](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112009715.png)

![image-20191016112023303](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112023303.png)

### Big Omega and Theta

#### 1. Big Omega

![image-20191016112110386](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112110386.png)

#### 2. Theta

![image-20191016112203897](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112203897.png)

## Slide 3

#### In place

![image-20191016112957219](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016112957219.png)

#### Stability

![image-20191016113322414](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016113322414.png)

#### Insertion Sort

~~~cpp
void insertSort(int* nums, int length){
    for(int i = 1 ; i<length;i++)
    {
        int tmp = nums[i],j = i-1;
        while(j>=0 && tmp < nums[j])
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = tmp;
    }
}
~~~

#### Bubble Sort

~~~cpp
void bubbleSort(int *nums, int length)
{
    for(int i = 0 ; i<length-1;i++)
    {
        for (int j = 0; j < length-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(j,j+1,nums);
            }
        }
    }
}
~~~

####  Selection Sort

~~~cpp
void selectionSort(int*nums,int length)
{
    for(int i = 0 ;i < length - 1;i++)
    {
        int min = INT32_MAX;
        int minAt = i;
        for(int j = i ; j< length;j++)
        {
            if(nums[j]<min)
            {
                min = nums[j];
                minAt = j;
            }
        }
        swap(i,minAt,nums);
    }
}
~~~

 #### Merge Sort

![image-20191016115344749](/Users/makersmelx/OneDrive/OneDrive - sjtu.edu.cn/JI/2019FA/VE281/mid/mid.assets/image-20191016115344749.png)

#### Master Method

$$
T(n) \leq a T\left(\frac{n}{b}\right)+O\left(n^{d}\right)
$$

$$
T(n)=\left\{\begin{array}{ll}{O\left(n^{d} \log n\right)} & {\text { if } a=b^{d}} \\ {O\left(n^{d}\right)} & {\text { if } a<b^{d}} \\ {O\left(n^{\log _{b} a}\right)} & {\text { if } a>b^{d}}\end{array}\right.
$$

#### Quick Sort

~~~cpp
void quickSort(int* nums,int left,int right)
{
    if(left >= right)
    {
       return ;
    }
    int pivotIndex = rand() % (right - left + 1) + left;
    swap(left,pivotIndex,nums);
    int pivotat = left;
    int i = left + 1, j = i;
    for (; j <= right; j++)
    {
        if (nums[j] < nums[pivotat])
        {
            swap(i,j,nums);
            i++;
        }
    }
    swap(i-1,pivotat,nums);
    quickSort(nums,left, i - 2);
    quickSort(nums,i, right);
}
~~~

| size n        | Best              | Average                | Worst                 | Stable | In-place | S(n)                  |
| ------------- | ----------------- | ---------------------- | --------------------- | ------ | -------- | --------------------- |
| Linear search | $\Omega(1)$       | $\mathcal{O}(n)$       | $\mathcal{O}(n)$      | NULL   | YES      | $\mathcal{O}(1)$      |
| bianry search | $\Omega(1)$       | $\mathcal{O}(\log n)$  | $\mathcal{O}(\log n)$ | NULL   | NO       | $\mathcal{O}(\log n)$ |
| selection     | $\Theta(n^2)$     | $\mathcal{O}(n^2)$     | $\mathcal{O}(n^2)$    | NO     | YES      | $\mathcal{O}(1)$      |
| bubble        | $\Theta(n^2)$     | $\mathcal{O}(n^2)$     | $\mathcal{O}(n^2)$    | YES    | YES      | $\mathcal{O}(1)$      |
| insertion     | $\Omega(n)$       | $\mathcal{O}(n^2)$     | $\mathcal{O}(n^2)$    | YES    | YES      | $\mathcal{O}(1)$      |
| merge         | $\Theta(n\log n)$ | $\Theta(n\log n)$      | $\mathcal{O}(n^2)$    | YES    | NO       | $\mathcal{O}(n)$      |
| quick         | $\Omega(n\log n)$ | $\mathcal{O}(n\log n)$ | $\mathcal{O}(n^2)$    | NO     | Weakly   |                       |

$$
\begin{align*}
	T(n)&= \Theta(n)+T(k)+T(n-1-k) \\
		&= cn + \frac{1}{n}\sum_{i=0}^{n-1}(T(i)+T(n-1-i))
\end{align*}
$$

$$
\begin{align*}  
nT(n)&=  cn^2 + 2\sum_{i=0}^{n-1}T(i) \\
(n-1)T(n-1)&=  c(n-1)^2 + 2\sum_{i=0}^{n-2}T(i) \\
nT(n)-(n-1)T(n-1)&=c(2n-1)+2T(n-1) \\
\frac{T(n)}{n+1} &= \frac{c(2n-1)}{n(n+1)}+\frac{T(n-1)}{n} \\
T(n)&=2c \int_0^{n-1}\frac{1}{k+1}
\end{align*}
$$

## Rehashing



