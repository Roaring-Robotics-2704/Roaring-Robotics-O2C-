#ifndef AUTONOMOUS_ENTRY_H
#define AUTONOMOUS_ENTRY_H

class AutonomousEntry{
private:
	vector<unsigned long> times;
	vector<vector<double> > values;
	string name = "";
public:
	size_t ix = 0;

	AutonomousEntry(unsigned long a, unsigned long b){
		stringstream s;
		s << a;
		s << "_";
		s << b;
		s << "-frc-2704-robot-autonomous-save.txt";
	}

	double peekAtNextValues(){
		if(ix < times.size())
			return times[ix];
		return -1.0;
	}
	pair<vector<double>, double>* getNextValues(){
		if(ix < times.size()){
			pair<vector<double>, double>* ret = new pair<vector<double>, double>(values[ix], times[ix]);
			ix ++;
			return ret;
		}
		return NULL;
	}
	void putLastValues(vector<double> data, double t){
		values.push_back(data);
		times.push_back(t);
	}
	void clear(){
		times.clear();
		values.clear();
	}
	void save(string filename){
		if(name == ""){
			return;
		}
		ofstream ofs(filename);
		for(unsigned long a : times){
			ofs << a << " ";
		}
		ofs << "/ ";
		for(vector<double> d2 : values){
			for(double d : d2){
				ofs << d << " ";
			}
			ofs << "; ";
		}
		ofs << "/ ";
	}
	void load(string filename){
		ifstream ifs(filename);
		if(!ifs.is_open()){
			return;
		}
		clear();

		string a;
		for(;;){
			ifs >> a;
			if(a == "/"){
				break;
			}
			unsigned long b;
			stringstream(a) >> b;
			times.push_back(b);
		}
		for(;;){
			ifs >> a;
			if(a == "/"){
				break;
			}
			for(;;){
				string c;
				ifs >> c;
				if(c == ";"){
					break;
				}
				double b;
				stringstream(c) >> b;
				values[values.size() - 1].push_back(b);
			}
		}
	}
};

#endif
