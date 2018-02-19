#ifndef AUTONOMOUS_ENTRY_H
#define AUTONOMOUS_ENTRY_H

class AutonomousEntry{
private:
	vector<unsigned long> sizes;
	vector<double> values;
	string name = "";
public:
	size_t ixS = 0;
	size_t ixV = 0;

	AutonomousEntry(unsigned long a, unsigned long b){
		stringstream s;
		s << a;
		s << "_";
		s << b;
	}

	pair<vector<double>, double>* peekAtNextValues(){
		size_t ixS2 = ixS;
		size_t ixV2 = ixV;
			if(ixS2 >= sizes.size()){
				return NULL;
			}
			vector<double> data;
			double t;
			size_t a=0;
			for(; a<sizes[ixS2]; a++){
				data.push_back(values[ixV2 ++]);
			}
			t = values[ixV2 ++];

			return new pair<vector<double>, double>(data, t);
	}
	pair<vector<double>, double>* getNextValues(){
		if(ixS >= sizes.size()){
			return NULL;
		}
		vector<double> data;
		double t;
		size_t a=0;
		for(; a<sizes[ixS]; a++){
			data.push_back(values[ixV ++]);
		}
		t = values[ixV ++];

		ixS ++;
		return new pair<vector<double>, double>(data, t);
	}
	void putLastValues(vector<double> data, double t){
		size_t six = sizes.size();
		sizes.push_back(0);
		for(double d : data){
			values.push_back(d);
		}
		values.push_back(t);
		sizes[six] = data.size();
	}
	void clear(){
		sizes.clear();
		values.clear();
	}
	void save(string filename){
		if(name == ""){
			return;
		}
		ofstream ofs(filename);
		for(unsigned long a : sizes){
			ofs << a << " ";
		}
		ofs << "/ ";
		for(double v : values){
			ofs << v << " ";
		}
		ofs << "/ ";
	}
	void load(string filename){
		clear();
		ifstream ifs(filename);
		string a;
		for(;;){
			ifs >> a;
			if(a == "/"){
				break;
			}
			unsigned long b;
			stringstream(a) >> b;
			sizes.push_back(b);
		}
		for(;;){
			ifs >> a;
			if(a == "/"){
				break;
			}
			double b;
			stringstream(a) >> b;
			values.push_back(b);
		}
	}
};

#endif