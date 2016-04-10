#Kairos 
Kairos is a C++ Library that help you to save the state of your applications at the opportune moment. Kairos is an ancient Greek word meaning the right or opportune moment.

##How does it works
Kairos to save the state of your applications it use what is called *Serialization*, and to restore it use the reversed process: *Deserialization*.

###Serialization
In Computer Science, *Serialization* is the process of "conversion" data structures or objects into a format that can be stored (for example, in a file or memory buffer, or a string that can be transmitted across the network, normaly a JSON or XML string) and reconstructed later using deserialization that is the reversed process. Two Different format of Serialization are possible in Kairos, **Text** and **Binary**, the text format save objects in a readable form, this format can be useful for debugging. The binary format convert objects in binary format (is not readable).

###How to Serialize
Objects to be serialized must extend the clas **Serializable** and **Serialization**, and then provide an implementation for *serialize(Archive&)*, *deserialize(Archive&)*.    
Example:
        
```c++
     
class Object : public Serializable, public Serialization {    
private:     
	int data;    
	float data1;    
	char data2;    

public:
	// a default constructor is necessary for deserialization
	Object() {
		// register Object, by default use text format   
		registerType(this);       
		
		// if you want to use binary format
		// registerType(this, Serialization::BINARY);    
	}  

	void serialize(Archive& archive) {
		archive << data << data1 << data2;
	}
	
	void deserialize(Archive& archive) {
		archive >> data >> data1 >> data2;
	}
	 
};  
```    
From the example above you can see how simple and clean is the usage of Kairos.  When you declare your object as serialazble, the serialization process generate a unique id for the object (this is caused by the call *registerType*) and the pair<object, id> is added in a internal map. The object is actually saved when the method *Serialization::createCheckpoint* is called:   
Example:

```c++
....

 Object* object1 = new Object(0, 2.3, 'a');

 // createCheckpoint can throw a SerializationException* 
 try {
 	Serialization::createCheckpoint(object1);

 } catch (SerializationException* exp) {
 	std::cout << exp->what() << std::endl;
 }
 
....

```   
The static method *createCheckpoint* create a local file with the following format:

```
//archive.format.class_name.id_object
archive.text.Object.1234

```




