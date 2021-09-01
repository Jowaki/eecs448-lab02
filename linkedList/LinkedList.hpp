/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
  return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO 
		Fix this method
	*/
	Node<T>* current = m_front;
	if(m_front == nullptr)
	  {
	    isFound=false;
	  }
	else if (m_front->getValue() == value)
	  {
	    isFound=true;
	  }
	else
	  {
	    for(int i=1;i<=m_size;i++)
	      {
		if (current->getValue()==value)
		  {
		    isFound=true;
		  }
		else
		  {
		    current=current->getNext();
		  }
	      }
	  }
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO 
		Fix this method
	*/
	if(m_front==nullptr)
	  {
	    isRemoved=false;
	  }
	else if(m_size!=0)
	  {
	    secondintoLast=m_front;
	      for(int i =1;i<m_size-1;i++)
	      {
			secondintoLast=secondintoLast->getNext();
	      }

	     lastNode=secondintoLast->getNext();
	     if (lastNode != nullptr)
		{		  
		  isRemoved=true;
		  secondintoLast->setNext(nullptr);
		  delete lastNode;
		  m_size--;
		}
	  }
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
