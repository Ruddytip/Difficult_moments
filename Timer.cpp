#include "Timer.hpp"

double Timer::elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

Timer::Timer(std::string name) : m_name(name), m_beg(clock_t::now()){}

std::ostream& operator<<(std::ostream& out, const Timer& timer){
    out << timer.m_name << ":\t" << timer.elapsed() * 1000 << " ms";
    return out;
}
