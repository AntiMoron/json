#ifndef CONFIG_HPP
#define CONFIG_HPP

//�ж��Ƿ�Ϊcxx11��������������µĺ���Ϊ�ж�
#if __cplusplus>=201103U
#define COMPILE_CXX11
#define NIL nullptr
#else
#define NIL NULL
#endif

#endif // CONFIG_HPP
