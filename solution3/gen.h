
template<typename T>
struct Generator {
    T m_value, m_step;
    Generator(T initial, T step):m_value(initial), m_step(step){};
    T operator()() {
        T cur_value = m_value;
        m_value += m_step;
        return cur_value;
    }
};
