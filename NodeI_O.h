#pragma once
class NodeI_O
{
private:
	int item;
	int item2;
public:
	NodeI_O();
	NodeI_O( int& r_Item, int& r_Item2);
	void setItem( int& r_Item);
	int getItem() const;
	void setItem2( int& r_Item2);
	int getItem2() const;

};

NodeI_O::NodeI_O()
{
}

NodeI_O::NodeI_O(int& r_Item,  int& r_Item2)
{
	item = r_Item;
	item2 = r_Item2;
}

void NodeI_O::setItem( int& r_Item)
{
	item = r_Item;
	
}

void NodeI_O::setItem2( int& r_Item2)
{
	item2 = r_Item2;

}

int NodeI_O::getItem() const
{
	return item;
}


int NodeI_O::getItem2() const
{
	return item2;
}
