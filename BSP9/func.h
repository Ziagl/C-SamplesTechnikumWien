//ein Functor: eine Klasse die wie eine Funktion verwendet wird
class func{
public:
	func(int a, int b);
	int operator()();
private:
	int a, b;
};

func::func(int a, int b)
{
	this->a = a;
	this->b = b;
}

int func::operator ()()
{
	double r = b - a + 1;
	return a + static_cast<int>(r*rand()/(RAND_MAX+1.0));
}