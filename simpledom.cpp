#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include <iostream>
#include <fstream> 
using namespace rapidjson;
using namespace std;

int one(); 
int two(); 

int one(){
	// parse a JSON string into DOM 
	const char* json = "{\"project\":\"rapidjson\", \"stars\":10}";
	Document d; 
	d.Parse(json); 

	// Modify it by DOM 
	Value& s = d["stars"]; 
	s.SetInt(s.GetInt() +1);

	// Stringify the DOM 
	StringBuffer buffer;
	Writer <StringBuffer> writer(buffer);
	d.Accept(writer); 



	//output {"project":"rapidjson", "stars":11} 
	cout << buffer.GetString() << endl;
	return 0; 


}



int two(){

	char json[] = " {\"name\" : \"sudhakar\", \"age\" : 39, \"occupasion\" : \"Engineer\", \"married\" : true, \"kids\":true}"; 

	Document document; 
	document.Parse(json);


	printf("\nAccess values in the document : \n"); 
	assert(document.IsObject()); 

	assert(document.HasMember("name"));
	assert(document["name"].IsString());
	printf("name = %s\n", document["name"].GetString());
	
	assert(document.HasMember("occupasion"));
	assert(document["occupasion"].IsString());
	printf("occupasion = %s\n", document["occupasion"].GetString());
	assert(document.HasMember("kids"));
	assert(document["kids"].IsBool());
	printf("kids = %d\n", document["kids"].GetBool());
	assert(document.HasMember("married"));
	assert(document["married"].IsBool());
	printf("married = %d\n", document["married"].GetBool());

	assert(document.HasMember("age"));
	assert(document["age"].IsInt());
	printf("age = %d\n", document["age"].GetInt());

	// access using iteration 

	// Value::MemberIterator name = document.findMember("name"); 
	// // check if this is not the last member 
	// assert(name != document.MemberEnd()); 

	// assert(name->value.IsString()); 

	// (void)name; 

	// assert(document[""])




	return 1; 

}

int three(){

	ifstream ifs("/Users/sudhakar/eyeem/mobile/porting/models/lg/orig/concepts-threshold.json"); 

	IStreamWrapper isw(ifs); 
	Document d;
	d.ParseStream(isw); 
	assert(d.HasMember("mappings"));
	printf ("Eclipse threshold : %f", d["eclipse"].GetDouble());
	
	return 1; 
}

int four(){

	ifstream ifs("/Users/sudhakar/eyeem/mobile/porting/models/lg/orig/concepts-mapping.json"); 
	IStreamWrapper isw(ifs); 
	Document d; 

	d.ParseStream(isw); 
	const Value& m = d["mappings"]["outdoor"]; 

	//assert(m.IsArrary()); 

	for (SizeType i =0; i < m.Size(); i++)
		printf("mappings[%d] = %s\n", i, m[i].GetString());

	const Value& mb = d["mappings"]["bird"]; 

	for (SizeType i =0; i < mb.Size(); i++)
		printf(" [\"mappings\"][\"bird\"][%d] = %s\n", i, mb[i].GetString());
	

	return 1; 


}


int main(){

	four(); 
	return 1; 
}