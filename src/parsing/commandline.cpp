namespace et::parsing::commandline
{
    template <typename datatype>
    datatype *to_type(int argc, char **argv)
    {
        datatype *parsed_list = new datatype{};

        for (int i = 1; i < argc; i++)
        {
            std::istringstream iss(argv[i]);
            typename datatype::value_type raw_word;
            iss >> raw_word;
            parsed_list->push_back(raw_word);
        }

        return parsed_list;
    }
};