template <typename T> struct qiu{
	stack<pair<T,T>> s1,s2;
	T query(){
		T mini;
		if (s1.empty() || s2.empty()) mini = s1.empty() ? s2.top().s : s1.top().s;
		else mini = min(s1.top().s, s2.top().s);
		return mini;
	}

	void pop(){
		if (s2.empty())while (!s1.empty()) {
        T e = s1.top().f;
        s1.pop();
        T mini = s2.empty() ? e : min(e, s2.top().s);
        s2.push({e, mini});
    	}
		T rem = s2.top().f;
		s2.pop();
	}

	void add(T new_e){
		T mini = s1.empty() ? new_e : min(new_e, s1.top().second);
		s1.push({new_e, mini});
	}
};
