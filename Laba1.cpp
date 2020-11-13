

#include "pch.h"
#include <iostream>

	void binary_set_relation(T_binary_relation const &binary_relation)
{
		int n = binary_relation.size();

		cout << "\n";
		cout << "1. Binary relation in the form of intersection of sets using upper cuts" << endl;
		for (int j = 0; j < n; j++) {
			cout << "R+(X" << j << ")={";
			for (int i = 0; i < n; i++) {
				if (binary_relation[i][j]) { cout << "X" << i << " "; }
			}
			cout << "}\n";
		}

		cout << "2. Binary relation in the form of intersection of sets using lower cuts";
		for (int i = 0; i < n; i++) {
			cout << "R-(X" << i << ")={";
			for (int j = 0; j < n; j++) {
				if (binary_relation[i][j]) { cout << "X" << j << " "; }
			}
			cout << "}\n";
		}
	}


	bool binary_relation_is_reflexive(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; ++i) {
			bool_res = binary_relation[i][i] == 1;

			if (!bool_res)
			{
				return  bool_res;
			}
		}

		return  bool_res;
	}


	bool binary_relation_is_antireflexive(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; ++i) {
			bool_res = binary_relation[i][i] == 0;

			if (!bool_res)
			{
				return  bool_res;
			}
		}

		return  bool_res;
	}


	bool binary_relation_is_symmetric(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				bool_res = binary_relation[i][j] == binary_relation[j][i];

				if (!bool_res)
				{
					return  bool_res;
				}
			}
		}

		return  bool_res;
	}


	bool binary_relation_is_asymmetric(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; ++i) {
			bool_res = binary_relation[i][i] == 0;

			if (!bool_res)
			{
				return  bool_res;
			}

			for (int j = i + 1; j < n; ++j) {
				bool_res = binary_relation[i][j] == binary_relation[j][i];

				if (bool_res)
				{
					return  bool_res;
				}
			}
		}

		return  bool_res;
	}


	bool binary_relation_is_antisymmetric(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				bool_res = binary_relation[i][j] * binary_relation[j][i] == 0;

				if (!bool_res)
				{
					return  bool_res;
				}
			}
		}

		return  bool_res;
	}

	bool binary_relation_is_transitive(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// if there is a directed edge connecting vertices i and j
				if (binary_relation[i][j]) {
					for (int z = 0; z < n; z++) {
						// if an edge leads from vertex j to vertex z, but not from i to z, then the graph is nontransitive
						if (binary_relation[j][z] && !binary_relation[i][z]) {
							return  !bool_res;
						}
					}
				}
			}
		}
		return  bool_res;
	}

	bool binary_relation_is_acyclicitive(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		T_binary_relation buffer_matrix(n, T_row(n));

		// multiply matrices
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					buffer_matrix[i][j] += binary_relation[i][k] * binary_relation[k][j];
					if (buffer_matrix[i][j]) {
						buffer_matrix[i][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			bool_res = min(binary_relation[i][i], buffer_matrix[i][i]) == 0;

			if (!bool_res)
			{
				return  bool_res;
			}
		}

		return  bool_res;
	}

	void complement_relation(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();

		cout << "3 Supplement relationship";
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (binary_relation[i][j]) {
					cout << "0" << "\t";
				}
				else { cout << "1" << "\t"; }
			}
			cout << "\n";
		}


	}

	void inverse_relation(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();

		cout << "4 Reverse relation";
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << binary_relation[j][i] << "\t";
			cout << "\n";
		}
	}

	void strong_relation(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();

		cout << "5 Strict relation ";
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (binary_relation[i][j]) {
					if (binary_relation[i][j] > binary_relation[j][i]) {
						cout << "1" << "\t";
					}
					else { cout << "0" << "\t"; }
				}
				else { cout << "0" << "\t"; }
			}
			cout << "\n";
		}
	}

	void equivalence_ratio(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;

		cout << "6. The equivalent relation";
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << min(binary_relation[i][j], binary_relation[j][i]) << "\t";
			cout << "\n";
		}
	}

	void analysis(T_binary_relation const &binary_relation)
	{
		int n = binary_relation.size();
		bool bool_res = true;
		int count0 = 0;
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int row = 0;
		int column = 0;
		cout << "\n";
		for (int i = 0; i < n; i++) {
			row = 0;
			for (int j = 0; j < n; j++) {
				row += binary_relation[i][j];
			}
			if (row == n) {
				count0++;
				cout << " Max Х" << i << endl;
			}if (row == 0) {
				count2++;
				cout << " Min X" << i << endl;
			}
		}
		for (int j = 0; j < n; j++) {
			column = 0;
			for (int i = 0; i < n; i++) {
				column += binary_relation[i][j];
			}
			if (column == n) {
				count1++;
				cout << " Min X" << j << endl;
			} if (column == 0) {
				count3++;
				cout << " Max X" << j << endl;
			}
		}

		if (count0 == 0) { cout << " There is no maximum" << endl; }
		if (count1 == 0) { cout << " There is no minimum " << endl; }
		if (count2 == 0) { cout << " There is no minorant " << endl; }
		if (count3 == 0) { cout << " There is no majorant " << endl; }
	}


	template< typename  TT_func_ptr >

	void    print_message_and_func_result(T_str const & message, TT_func_ptr func_ptr, T_binary_relation const & binary_relation)
	{
		cout << message << (func_ptr(binary_relation) ? "yes" : "no") << endl;
	}

	void check_binary_relation_and_print_result(T_binary_relation const & binary_relation)
	{
		print_message_and_func_result("2.1 Reflexivity\t\t: ", binary_relation_is_reflexive, binary_relation);
		print_message_and_func_result("2.2 Anti-reflectiveness\t\t: ", binary_relation_is_antireflexive, binary_relation);
		print_message_and_func_result("2.3 Symmetry\t\t: ", binary_relation_is_symmetric, binary_relation);
		print_message_and_func_result("2.4 Asymmetry\t\t: ", binary_relation_is_symmetric, binary_relation);
		print_message_and_func_result("2.5 Antisymmetry\t\t: ", binary_relation_is_antisymmetric, binary_relation);
		print_message_and_func_result("2.6 Transitivity\t\t: ", binary_relation_is_transitive, binary_relation);
		print_message_and_func_result("2.7 Acyclicity\t\t: ", binary_relation_is_acyclicitive, binary_relation);
	}

	int main()
	{
		
		// Create a file stream and link it to the file
		ifstream in("Variant4.txt");

		if (in.is_open())
		{
			// If opening the file was successful

			// First, count how many numbers are in the file
			int count = 0;// number of numbers in file
			int temp;// Temporary variable

			while (!in.eof())// run until we reach the end of the file eof
			{
				in >> temp;//read numbers from the file into the void
				count++;// increase the counter of the number of numbers
			}

			// First, move the caret in the stream to the beginning of the file
			in.seekg(0, ios::beg);
			in.clear();

			// The number of spaces in the first line is initially 0
			int count_space = 0;
			char symbol;
			while (!in.eof())// just in case, the loop is limited to the end of the file
			{
				// now we need to read not numbers, but read data character by character
				in.get(symbol);// read the current symbol
				if (symbol == ' ') count_space++;// If it's a space, then the number of spaces is increased
				if (symbol == '\n') break;// If we reach the end of the line, then exit the loop
			}
			

			// Go to the beginning of the file again
			in.seekg(0, ios::beg);
			in.clear();

			// Now we know how many numbers are in the file and how many spaces are in the first line.
			// Now we can read the matrix
			int n = count_space + 1;
			T_binary_relation binary_relation(n, T_row(n));

			// Read the matrix from the file
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					in >> binary_relation[i][j];

			// Output the matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << binary_relation[i][j] << "\t";
				cout << "\n";
			}
			cout << endl;
			binary_set_relation(binary_relation);
			cout << endl;
			check_binary_relation_and_print_result(binary_relation);
			cout << endl;
			complement_relation(binary_relation);
			cout << endl;
			inverse_relation(binary_relation);
			cout << endl;
			strong_relation(binary_relation);
			cout << endl;
			equivalence_ratio(binary_relation);
			cout << endl;
			analysis(binary_relation);
			in.close();// close the file at the end
		}
		else
		{
			// If opening the file was not successful
			cout << "File not found.";
		}

	}