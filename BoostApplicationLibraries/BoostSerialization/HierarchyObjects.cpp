//HierarchyObjects.cpp
//
//Serialization of Class Hierarchy Objects
//

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
#include <iostream>

/*---------------------------------------------------------------------------
//11. Serializing derived classes correctly

std::stringstream ss;

class animal
{
public:
	animal() = default;
	animal(int legs) :legs_{ legs } {}
	int legs() const { return legs_; }

private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & legs_;
	}

	int legs_;
};

class bird :public animal
{
public:
	bird() = default;
	bird(int legs, bool can_fly):animal{legs}, can_fly_{can_fly}{}
	bool can_fly() const { return can_fly_; }

private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<animal>(*this);
		ar & can_fly_;
	}

	bool can_fly_;
};

void save()
{
	boost::archive::text_oarchive oa{ ss };
	bird penguin{ 2, false };
	oa << penguin;
}

void load()
{
	boost::archive::text_iarchive ia{ ss };
	bird penguin;
	ia >> penguin;
	
	std::cout << penguin.legs() << '\n';
	std::cout << std::boolalpha << penguin.can_fly() << '\n';
}

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
//12. Registering derived classes statically with BOOST_CLASS_EXPORT
#include <boost/serialization/export.hpp>

using namespace boost::archive;

class animal
{
public:
	animal() = default;
	animal(int legs) :legs_{ legs } {}
	virtual int legs()const { return legs_; }
	virtual ~animal() = default;
private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const signed int version) { ar&legs_; }

	int legs_;
};


class bird :public animal
{
public:
	bird() = default;
	bird(int legs, bool can_fly) :animal{ legs }, can_fly_{ can_fly } {}
	bool can_fly() const { return can_fly_; }

private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<animal>(*this);
		ar & can_fly_;
	}

	bool can_fly_;
};

BOOST_CLASS_EXPORT(bird)

std::stringstream ss;

void save()
{
	text_oarchive oa{ ss };
	animal *a = new bird{ 2, false };
	oa << a;
	delete a;
	//std::cout << ss.str() << std::endl;
}

void load()
{
	text_iarchive ia{ ss };
	animal *a;
	ia >> a;
	bird *b = (bird*)(a);
	std::cout << b->legs() << std::endl;
	std::cout << std::boolalpha << b->can_fly() << std::endl;
	delete a;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
//13. Registering derived classes dynamically with register_type()
using namespace boost::archive;

class animal
{
public:
	animal() = default;
	animal(int legs) :legs_{ legs } {}
	virtual int legs()const { return legs_; }
	virtual ~animal() = default;
private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const signed int version) { ar&legs_; }

	int legs_;
};

class bird :public animal
{
public:
	bird() = default;
	bird(int legs, bool can_fly) :animal{ legs }, can_fly_{ can_fly } {}
	bool can_fly() const { return can_fly_; }

private:
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<animal>(*this);
		ar & can_fly_;
	}

	bool can_fly_;
};

std::stringstream ss;

void save()
{
	text_oarchive oa{ ss };
	oa.register_type<bird>();
	animal *a = new bird{ 2, false };
	oa << a;
	delete a;
}

void load()
{
	text_iarchive ia{ ss };
	ia.register_type<bird>();
	animal *a;
	ia >> a;
	std::cout << a->legs() << std::endl;
	delete a;
}

/*---------------------------------------------------------------------------*/

int main()
{
	save();
	load();

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}