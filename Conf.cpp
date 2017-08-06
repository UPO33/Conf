
const char* gStrTest = "a = 0, { b = 1, c = 2}";

#include <string>
#include <vector>
#include <iostream>

struct ConfNode
{
	size_t ChildCount() const { return mChildren.size(); }


	bool HasName() const { return !mName.empty(); }
	bool HasValue() const { return mChildren.size() == 0; }
	bool IsParent() const { return mChildren.size() > 0; }

	std::string				mName;
	std::string				mValue;
	std::vector<ConfNode>	mChildren;
};

template<typename TChar> void ConfRead(const TChar* inString, ConfNode& outRoot)
{
	typedef const TChar* CStr;

	auto TrimSpace = [](CStr& str) {
		while (TChar chr = *str)
		{
			if (isspace(chr))
				str++;
			else
				break;
		}
	};



}

void PrintNode(const ConfNode& node, int intent = 0)
{
	for (int i = 0; i < intent; i++) std::cout << "  ";

	for (const ConfNode child : node.mChildren)
	{
		std::cout << child.mName << " = " << child.mValue << "\n";

		PrintNode(child, intent + 1);
	}
}
int main()
{
	ConfNode root;
	ConfRead(gStrTest, root);
	PrintNode(root);

	system("pause");
    return 0;
}

