template <class T>
class MaxPQ {
public:
	virtual ~MaxPQ() {};
	virtual bool IsEmpty() const = 0;
	virtual const T& Top() const = 0;
	virtual void push(const T&) = 0;
	virtual void Pop() = 0;
};