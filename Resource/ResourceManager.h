#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <unordered_map>
#include <string>

template<typename Resource> class ResourceManager
{
public:
	ResourceManager(const char* folder, const char* ext) : Folder(folder), Ext(ext)
	{
	}

	const Resource& GetResource(const char* filename, bool isfullpath = false)
	{
		if (!FileExists(filename))
		{
			AddResource(filename, isfullpath)
		}
		return ResourceMap[filename];
	}

	void Remove(const char* filename)
	{
		ResourceMap.erase(filename);
	}
	

private:
	void AddResource(const char* filename, bool isfullpath = false)
	{
		Resource Res;

		std::string str = isfullpath ? filename : BuildString(filename);

		if (!Res.loadFromFile(str))
		{
			Res.loadFromFile(BuildString("fail"));
		}
		ResourceMap.emplace(filename, Res);
	}

	std::string BuildString(const std::string& filename) const
	{
		return Folder + filename + "." + Ext;
	}

	bool FileExists(const char* filename) const
	{
		return this->ResourceMap.find(filename) != this->ResourceMap.end();
	}

	std::unordered_map<std::string, Resource> ResourceMap;

	std::string Folder;
	std::string Ext;

};

#endif