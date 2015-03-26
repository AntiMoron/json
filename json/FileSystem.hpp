#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include<cstdio>
#include<string>
#include"config.hpp"

namespace MEOJ
{
	class FileSystem
	{
	public:
		//�����ļ�·����ȡ�ļ�����
		static const std::string readFileContext(const char* fileName)
		{
			std::FILE* fp = NIL;
			std::string fileContext;
			fp = std::fopen(fileName,"r");
			//��ʱfp��ȻΪnullֵ���ȡ�ļ�ʧ�ܣ�����false
			if(!fp)
			{
				return "";
			}
			fileContext = "";
			while(!std::feof(fp))
			{
				fileContext += std::fgetc(fp);
			}
			if(!!fp)
			{
				std::fclose(fp);
			}
			return fileContext;
		}
		static bool writeFileContext(const char* fileName,const std::string& fileContext)
		{
			std::FILE* fp = NIL;
			fp = std::fopen(fileName,"w");
			if(!fp)
			{
				return false;
			}
			for(std::string::size_type i = 0;i < fileContext.length(); i++)
			{
				std::fputc(fileContext[i],fp);
			}
			if(!!fp)
			{
				std::fclose(fp);
			}
			return true;
		}
	};
}


#endif // FILESYSTEM_HPP
