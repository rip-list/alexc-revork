#pragma once
#include<sqlite3.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>


namespace alexcrevork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	
	namespace Excel = Microsoft::Office::Interop::Excel;


	sqlite3* db = nullptr;

	

	/// <summary>
	/// Сводка для home
	/// </summary>
	public ref class home : public System::Windows::Forms::Form
	{
	public:
		home(void)
		{
			InitializeComponent();
			InitializeDatabase();
			LoadClientsData();
			LoadDishesData();
			LoadOrdersData();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ createBludo;
	private: System::Windows::Forms::Button^ createClient;
	protected:

	protected:

	private: System::Windows::Forms::Button^ createZakaz;
	private: System::Windows::Forms::TextBox^ inputClientName;
	private: System::Windows::Forms::TextBox^ inputClienNamber;
	private: System::Windows::Forms::TextBox^ inputBludoName;
	private: System::Windows::Forms::TextBox^ inputBludoPrice;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ report;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ orderNameClient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ orderDishes;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ orderDishesNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ currentTotalPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dishId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dishName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dishPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientNumber;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->createBludo = (gcnew System::Windows::Forms::Button());
			this->createClient = (gcnew System::Windows::Forms::Button());
			this->createZakaz = (gcnew System::Windows::Forms::Button());
			this->inputClientName = (gcnew System::Windows::Forms::TextBox());
			this->inputClienNamber = (gcnew System::Windows::Forms::TextBox());
			this->inputBludoName = (gcnew System::Windows::Forms::TextBox());
			this->inputBludoPrice = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->report = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dishId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dishName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dishPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->clientId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->orderNameClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->orderDishes = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->orderDishesNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->currentTotalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// createBludo
			// 
			this->createBludo->Location = System::Drawing::Point(358, 131);
			this->createBludo->Name = L"createBludo";
			this->createBludo->Size = System::Drawing::Size(109, 32);
			this->createBludo->TabIndex = 0;
			this->createBludo->Text = L"Добавить блюдо";
			this->createBludo->UseVisualStyleBackColor = true;
			this->createBludo->Click += gcnew System::EventHandler(this, &home::createBludo_Click);
			// 
			// createClient
			// 
			this->createClient->Location = System::Drawing::Point(559, 131);
			this->createClient->Name = L"createClient";
			this->createClient->Size = System::Drawing::Size(109, 32);
			this->createClient->TabIndex = 1;
			this->createClient->Text = L"Добавить клиента";
			this->createClient->UseVisualStyleBackColor = true;
			this->createClient->Click += gcnew System::EventHandler(this, &home::createClient_Click);
			// 
			// createZakaz
			// 
			this->createZakaz->Location = System::Drawing::Point(355, 251);
			this->createZakaz->Name = L"createZakaz";
			this->createZakaz->Size = System::Drawing::Size(122, 43);
			this->createZakaz->TabIndex = 2;
			this->createZakaz->Text = L"Создать заказ";
			this->createZakaz->UseVisualStyleBackColor = true;
			this->createZakaz->Click += gcnew System::EventHandler(this, &home::createZakaz_Click);
			// 
			// inputClientName
			// 
			this->inputClientName->Location = System::Drawing::Point(546, 40);
			this->inputClientName->Name = L"inputClientName";
			this->inputClientName->Size = System::Drawing::Size(130, 20);
			this->inputClientName->TabIndex = 5;
			// 
			// inputClienNamber
			// 
			this->inputClienNamber->Location = System::Drawing::Point(546, 96);
			this->inputClienNamber->Name = L"inputClienNamber";
			this->inputClienNamber->Size = System::Drawing::Size(130, 20);
			this->inputClienNamber->TabIndex = 6;
			// 
			// inputBludoName
			// 
			this->inputBludoName->Location = System::Drawing::Point(345, 40);
			this->inputBludoName->Name = L"inputBludoName";
			this->inputBludoName->Size = System::Drawing::Size(141, 20);
			this->inputBludoName->TabIndex = 7;
			// 
			// inputBludoPrice
			// 
			this->inputBludoPrice->Location = System::Drawing::Point(345, 96);
			this->inputBludoPrice->Name = L"inputBludoPrice";
			this->inputBludoPrice->Size = System::Drawing::Size(141, 20);
			this->inputBludoPrice->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(357, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Стоимость Блюда";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(357, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Название блюда";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(556, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Введите Имя Клиента";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(556, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Введите Номер Клиента";
			// 
			// report
			// 
			this->report->Location = System::Drawing::Point(559, 251);
			this->report->Name = L"report";
			this->report->Size = System::Drawing::Size(122, 43);
			this->report->TabIndex = 14;
			this->report->Text = L"Создать отчёт";
			this->report->UseVisualStyleBackColor = true;
			this->report->Click += gcnew System::EventHandler(this, &home::report_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dishId,
					this->dishName, this->dishPrice
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(327, 136);
			this->dataGridView1->TabIndex = 15;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &home::dataGridView1_CellClick);
			// 
			// dishId
			// 
			this->dishId->HeaderText = L"id";
			this->dishId->Name = L"dishId";
			this->dishId->Width = 50;
			// 
			// dishName
			// 
			this->dishName->HeaderText = L"Название ";
			this->dishName->Name = L"dishName";
			// 
			// dishPrice
			// 
			this->dishPrice->HeaderText = L"Цена";
			this->dishPrice->Name = L"dishPrice";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->clientId,
					this->clientName, this->clientNumber
			});
			this->dataGridView2->Location = System::Drawing::Point(12, 192);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(327, 135);
			this->dataGridView2->TabIndex = 16;
			this->dataGridView2->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &home::dataGridView2_CellClick);
			// 
			// clientId
			// 
			this->clientId->HeaderText = L"id";
			this->clientId->Name = L"clientId";
			this->clientId->Width = 50;
			// 
			// clientName
			// 
			this->clientName->HeaderText = L"Имя  ";
			this->clientName->Name = L"clientName";
			// 
			// clientNumber
			// 
			this->clientNumber->HeaderText = L"Номер";
			this->clientNumber->Name = L"clientNumber";
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->orderNameClient,
					this->orderDishes, this->orderDishesNumber, this->currentTotalPrice
			});
			this->dataGridView3->ImeMode = System::Windows::Forms::ImeMode::Close;
			this->dataGridView3->Location = System::Drawing::Point(12, 439);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->Size = System::Drawing::Size(709, 224);
			this->dataGridView3->TabIndex = 17;
			// 
			// orderNameClient
			// 
			this->orderNameClient->HeaderText = L"Имя";
			this->orderNameClient->Name = L"orderNameClient";
			this->orderNameClient->ReadOnly = true;
			// 
			// orderDishes
			// 
			this->orderDishes->HeaderText = L"Блюда";
			this->orderDishes->Name = L"orderDishes";
			this->orderDishes->ReadOnly = true;
			// 
			// orderDishesNumber
			// 
			this->orderDishesNumber->HeaderText = L"стоимость";
			this->orderDishesNumber->Name = L"orderDishesNumber";
			this->orderDishesNumber->ReadOnly = true;
			// 
			// currentTotalPrice
			// 
			this->currentTotalPrice->HeaderText = L"TotalPrice";
			this->currentTotalPrice->Name = L"currentTotalPrice";
			this->currentTotalPrice->ReadOnly = true;
			// 
			// home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 675);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->report);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inputBludoPrice);
			this->Controls->Add(this->inputBludoName);
			this->Controls->Add(this->inputClienNamber);
			this->Controls->Add(this->inputClientName);
			this->Controls->Add(this->createZakaz);
			this->Controls->Add(this->createClient);
			this->Controls->Add(this->createBludo);
			this->Name = L"home";
			this->Text = L"home";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int currentClientId = -1;  // Идентификатор текущего выбранного клиента
		String^ currentClientName;  // Имя текущего клиента

		void InitializeDatabase()
		{
			// Открытие базы данных
			if (sqlite3_open("database.db", &db) != SQLITE_OK) {
				MessageBox::Show("Ошибка открытия базы данных", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			// Создание таблицы клиентов
			const char* createClientsTable = "CREATE TABLE IF NOT EXISTS Clients (Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Phone TEXT);";

			// Создание таблицы блюд
			const char* createDishesTable = "CREATE TABLE IF NOT EXISTS Dishes (Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Price REAL);";

			// Создание таблицы заказов
			const char* createOrdersTable = "CREATE TABLE IF NOT EXISTS Orders (Id INTEGER PRIMARY KEY AUTOINCREMENT, ClientId INTEGER, TotalPrice REAL, DishNames TEXT, FOREIGN KEY(ClientId) REFERENCES Clients(Id));	";

			// Создание таблицы деталей заказов (связь заказов и блюд)
		
			// Выполнение запросов для создания таблиц
			ExecuteSQL(createClientsTable);
			ExecuteSQL(createDishesTable);
			ExecuteSQL(createOrdersTable);
			
		}

		// Выполнение SQL-запроса
		void ExecuteSQL(const char* sql)
		{
			char* errMsg = nullptr;
			int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
			if (rc != SQLITE_OK)
			{
				MessageBox::Show(gcnew String(errMsg), "Ошибка SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);
			}
			else
			{
				MessageBox::Show("SQL запрос выполнен успешно", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

		// Добавление клиента в базу данных
		void AddClientToDatabase(String^ name, String^ phone)
		{
			String^ query = "INSERT INTO Clients (Name, Phone) VALUES ('" + name + "', '" + phone + "');";
			const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());
			ExecuteSQL(sql);
		}

		// Добавление блюда в базу данных
		void AddDishToDatabase(String^ name, double price)
		{
			String^ query = "INSERT INTO Dishes (Name, Price) VALUES ('" + name + "', " + price + ");";
			const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());
			ExecuteSQL(sql);
		}

		// Загрузка данных клиентов
		void LoadClientsData()
		{
			dataGridView2->Rows->Clear();
			const char* sql = "SELECT * FROM Clients;";
			sqlite3_stmt* stmt;
			int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
			if (rc != SQLITE_OK)
			{
				MessageBox::Show("Не удалось выполнить запрос!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int id = sqlite3_column_int(stmt, 0);
				const char* name = (const char*)sqlite3_column_text(stmt, 1);
				const char* phone = (const char*)sqlite3_column_text(stmt, 2);
				dataGridView2->Rows->Add(id, gcnew String(name), gcnew String(phone));
			}

			sqlite3_finalize(stmt);
		}

		// Загрузка данных блюд
		void LoadDishesData()
		{
			dataGridView1->Rows->Clear();
			const char* sql = "SELECT * FROM Dishes;";
			sqlite3_stmt* stmt;
			int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
			if (rc != SQLITE_OK)
			{
				MessageBox::Show("Не удалось выполнить запрос!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int id = sqlite3_column_int(stmt, 0);
				const char* name = (const char*)sqlite3_column_text(stmt, 1);
				double price = sqlite3_column_double(stmt, 2);
				dataGridView1->Rows->Add(id, gcnew String(name), price);
			}

			sqlite3_finalize(stmt);
		}

		// Загрузка данных заказов
		void LoadOrdersData()
		{
			const char* sql = "SELECT Orders.Id, Clients.Name AS Client, Orders.DishNames, Orders.TotalPrice "
				"FROM Orders "
				"JOIN Clients ON Orders.ClientId = Clients.Id;";
			sqlite3_stmt* stmt;

			int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
			if (rc != SQLITE_OK)
			{
				MessageBox::Show("Не удалось выполнить запрос!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Чтение всех строк результата запроса
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				// Получаем данные из результатов запроса
				const char* clientName = (const char*)sqlite3_column_text(stmt, 1); // Имя клиента
				const char* dishNames = (const char*)sqlite3_column_text(stmt, 2); // Список блюд
				double totalPrice = sqlite3_column_double(stmt, 3);               // Итоговая сумма

				// Добавляем строку в DataGridView
				dataGridView3->Rows->Add(gcnew String(clientName), gcnew String(dishNames), totalPrice);
			}

			// Завершаем выполнение запроса
			sqlite3_finalize(stmt);
		}


		// Обработчик кнопки для добавления клиента
	private: System::Void createClient_Click(System::Object^ sender, System::EventArgs^ e) {

		// Проверка на заполнение полей
		if (!String::IsNullOrEmpty(inputClientName->Text) && !String::IsNullOrEmpty(inputClienNamber->Text)) {
			// Получение данных из TextBox
			String^ name = inputClientName->Text;
			String^ phone = inputClienNamber->Text;

			// Формирование SQL-запроса
			String^ query = "INSERT INTO Clients (Name, Phone) VALUES ('" + name + "', '" + phone + "');";
			const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());

			// Выполнение запроса
			ExecuteSQL(sql);

			// Очистка текстовых полей
			inputClientName->Clear();
			inputClienNamber->Clear();

			// Обновление данных в таблице
			LoadClientsData();
		}
		else {
			MessageBox::Show("Введите имя и номер клиента", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   // Обработчик кнопки для добавления блюда
	private: System::Void createBludo_Click(System::Object^ sender, System::EventArgs^ e) {


		// Проверка на заполнение полей
		if (!String::IsNullOrEmpty(inputBludoName->Text) && !String::IsNullOrEmpty(inputBludoPrice->Text)) {
			// Получение данных из TextBox
			String^ name = inputBludoName->Text;
			double price = Convert::ToDouble(inputBludoPrice->Text);

			// Формирование SQL-запроса
			String^ query = "INSERT INTO Dishes (Name, Price) VALUES ('" + name + "', " + price + ");";
			const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());

			// Выполнение запроса
			ExecuteSQL(sql);

			// Очистка текстовых полей
			inputBludoName->Clear();
			inputBludoPrice->Clear();

			// Обновление данных в таблице
			LoadDishesData();
		}
		else {
			MessageBox::Show("Введите название и цену блюда", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}


		   // 1. Переменные для хранения данных
private:
	System::Collections::Generic::List<String^>^ orderedDishes = gcnew System::Collections::Generic::List<String^>();  // Для хранения всех добавленных блюд
	System::Collections::Generic::List<double>^ orderedPrices = gcnew System::Collections::Generic::List<double>();    // Для хранения цен всех блюд
	System::Collections::Generic::List<int>^ orderedDishesId = gcnew System::Collections::Generic::List<int>();        // Для хранения ID блюд
	

	

	// 3. Обработчик клика по ячейке таблицы с клиентами
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Проверяем, что клик был не по заголовку
	if (e->RowIndex >= 0) {
		// Получаем ID блюда, название и цену
		int dishId = Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value);
		String^ dishName = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		double dishPrice = Convert::ToDouble(dataGridView1->Rows[e->RowIndex]->Cells[2]->Value);

		// Отладочное сообщение
		MessageBox::Show("Выбрано блюдо: " + dishName + ", Цена: " + dishPrice.ToString());

		// Проверяем, был ли выбран клиент
		if (currentClientId == -1) {
			MessageBox::Show("Выберите клиента перед добавлением блюда", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			// Добавляем выбранное блюдо в таблицу заказов
			AddDishToOrder(dishId, dishName, dishPrice);
		}
	}
}






	   // 4. Обработчик клика по ячейке таблицы с блюдами
private: System::Void dataGridView2_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Проверяем, что клик был не по заголовку
	if (e->RowIndex >= 0) {
		// Получаем ID клиента и имя клиента
		int clientId = Convert::ToInt32(dataGridView2->Rows[e->RowIndex]->Cells[0]->Value);
		String^ clientName = dataGridView2->Rows[e->RowIndex]->Cells[1]->Value->ToString();

		// Сохраняем данные о выбранном клиенте
		currentClientId = clientId;
		currentClientName = clientName;

		// Отладочное сообщение
		MessageBox::Show("Выбран клиент: " + currentClientId.ToString() + ", " + currentClientName);

		// Очищаем таблицу заказов и добавляем имя клиента
		dataGridView3->Rows->Clear();
		dataGridView3->Rows->Add(currentClientName);  // Имя клиента будет в первой строке
	}
}





	   // 5. Метод для добавления блюда в заказ
	   void AddDishToOrder(int dishId, String^ dishName, double dishPrice) {
		   // Ищем строку, соответствующую текущему клиенту
		   int clientRowIndex = -1;
		   for (int i = 0; i < dataGridView3->Rows->Count; i++) {
			   if (dataGridView3->Rows[i]->Cells[0]->Value != nullptr &&
				   dataGridView3->Rows[i]->Cells[0]->Value->ToString() == currentClientName) {
				   clientRowIndex = i;
				   break;
			   }
		   }

		   // Если строки для клиента нет, создаем ее
		   if (clientRowIndex == -1)
		   {
			   clientRowIndex = dataGridView3->Rows->Add(currentClientName); // Добавляем строку с именем клиента
			   dataGridView3->Rows[clientRowIndex]->Cells[1]->Value = ""; // Начальный список блюд (пустой)
			   dataGridView3->Rows[clientRowIndex]->Cells[2]->Value = nullptr; // Начальная сумма заказа (нулевая)
		   }

		   // Получаем текущий список блюд для клиента
		   String^ currentDishList = dataGridView3->Rows[clientRowIndex]->Cells[1]->Value == nullptr
			   ? "" // Если пусто, используем пустую строку
			   : dataGridView3->Rows[clientRowIndex]->Cells[1]->Value->ToString();

		   // Добавляем новое блюдо к списку блюд (если оно еще не добавлено)
		   if (!currentDishList->Contains(dishName)) {
			   currentDishList += dishName + " (" + dishPrice.ToString("F2") + "); "; // Форматируем цену до 2 знаков после запятой
			   dataGridView3->Rows[clientRowIndex]->Cells[1]->Value = currentDishList;
		   }

		   // Получаем текущую сумму заказа
		   double currentTotalPrice = Convert::ToDouble(dataGridView3->Rows[clientRowIndex]->Cells[2]->Value);

		   // Обновляем общую сумму с учётом добавленного блюда
		   currentTotalPrice += dishPrice;
		   dataGridView3->Rows[clientRowIndex]->Cells[2]->Value = currentTotalPrice;
		   orderedDishes->Add(dishName);   // Добавляем название блюда
		   orderedPrices->Add(dishPrice);  // Добавляем цену блюда
		   orderedDishesId->Add(dishId);   // Добавляем ID блюда
		   Console::WriteLine("Количество блюд в заказе: " + orderedDishes->Count);

	   }







	   // 6. Метод для добавления всех заказов в базу данных
private: System::Void createZakaz_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверка, что клиент выбран и блюда добавлены
	if (currentClientId != -1 && orderedDishes->Count > 0) {
		
			// Добавление заказа в базу данных
			AddAllOrdersToDatabase();

			// Очистка списков после добавления в базу
			orderedDishes->Clear();
			orderedPrices->Clear();
			orderedDishesId->Clear();

			// Очистка таблицы заказов
			dataGridView3->Rows->Clear();

			// Сообщение об успешном создании заказа
			MessageBox::Show("Заказ успешно создан", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
		
	}
	else {
		// Сообщение об ошибке, если клиент не выбран или блюда не добавлены
		MessageBox::Show("Выберите клиента и добавьте хотя бы одно блюдо", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

	   void AddAllOrdersToDatabase() {
		   // Создаем строку с именами блюд и суммируем все цены
		   String^ dishNames = "";
		   double totalPrice = 0;

		   for (int i = 0; i < orderedDishesId->Count; i++) {
			   int dishId = orderedDishesId[i];
			   double dishPrice = orderedPrices[i];
			   totalPrice += dishPrice;

			   // Добавляем блюдо в строку
			   String^ dishName = GetDishNameById(dishId);  //  есть метод для получения названия блюда по Id
			   dishNames += dishName + " (" + dishPrice.ToString("F2") + "); ";  // Форматируем цену до 2 знаков после запятой
		   }

		   // Добавление самого заказа в таблицу Orders
		   String^ query = "INSERT INTO Orders (ClientId, TotalPrice, DishNames) VALUES (" + currentClientId + ", " + totalPrice + ", '" + dishNames + "');";
		   const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());
		   ExecuteSQL(sql);

		   // Сообщение об успешном создании заказа
		   MessageBox::Show("Заказ успешно создан", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
	   }

	   String^ GetDishNameById(int dishId) {
		   // SQL запрос для получения названия блюда по его Id
		   String^ query = "SELECT Name FROM Dishes WHERE Id = " + dishId + ";";
		   const char* sql = (const char*)(Marshal::StringToHGlobalAnsi(query).ToPointer());

		   sqlite3_stmt* stmt;
		   int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
		   if (rc != SQLITE_OK) {
			   MessageBox::Show("Ошибка при подготовке запроса для получения названия блюда!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return "";
		   }

		   // Выполнение запроса и получение названия блюда
		   String^ dishName = "";
		   if (sqlite3_step(stmt) == SQLITE_ROW) {
			   dishName = gcnew String((const char*)sqlite3_column_text(stmt, 0));
		   }

		   sqlite3_finalize(stmt);
		   return dishName;
	   }



	   void ExportToExcel()
	   {
		   // Initialize Excel application
		   Microsoft::Office::Interop::Excel::Application^ excelApp
			   = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
		   excelApp->Visible = false;

		   // Create a new workbook
		   Microsoft::Office::Interop::Excel::Workbooks^ workbooks = excelApp->Workbooks;
		   Microsoft::Office::Interop::Excel::Workbook^ workbook = workbooks->Add(System::Type::Missing);
		   Microsoft::Office::Interop::Excel::Worksheet^ sheet =
			   safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(excelApp->ActiveSheet);

		   // Set worksheet name
		   sheet->Name = "Orders Report";

		   // Add headers to the worksheet
		   sheet->Cells[1, 1] = "ID Заказа";
		   sheet->Cells[1, 2] = "Клиент";
		   sheet->Cells[1, 3] = "Блюда";
		   sheet->Cells[1, 4] = "Сумма";

		   // Fetch data from the database
		   const char* sql = "SELECT Orders.Id, Clients.Name, Orders.DishNames, Orders.TotalPrice "
			   "FROM Orders "
			   "JOIN Clients ON Orders.ClientId = Clients.Id;";
		   sqlite3_stmt* stmt;
		   int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
		   if (rc != SQLITE_OK)
		   {
			   MessageBox::Show("Ошибка выполнения SQL-запроса!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		   }

		   // Write data into Excel
		   int row = 2; // Start writing from row 2
		   while (sqlite3_step(stmt) == SQLITE_ROW)
		   {
			   int orderId = sqlite3_column_int(stmt, 0);
			   const char* clientName = (const char*)sqlite3_column_text(stmt, 1);
			   const char* dishNames = (const char*)sqlite3_column_text(stmt, 2);
			   double totalPrice = sqlite3_column_double(stmt, 3);

			   sheet->Cells[row, 1] = orderId;
			   sheet->Cells[row, 2] = gcnew System::String(clientName);
			   sheet->Cells[row, 3] = gcnew System::String(dishNames);
			   sheet->Cells[row, 4] = totalPrice;

			   row++;
		   }

		   sqlite3_finalize(stmt);

		   // Save the workbook
		   try
		   {
			   workbook->SaveAs(System::Environment::CurrentDirectory + "report.xlsx",
				   System::Type::Missing, System::Type::Missing, System::Type::Missing,
				   false, false,
				   Microsoft::Office::Interop::Excel::XlSaveAsAccessMode::xlShared,
				   false, false,
				   System::Type::Missing, System::Type::Missing, System::Type::Missing);
			   workbook->Close(false, System::Type::Missing, System::Type::Missing);
			   excelApp->Quit();
			   MessageBox::Show("Отчет успешно сохранен!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }
		   catch (Exception^ ex)
		   {
			   MessageBox::Show("Ошибка при сохранении файла: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }

		   // Release COM objects
		   System::Runtime::InteropServices::Marshal::ReleaseComObject(sheet);
		   System::Runtime::InteropServices::Marshal::ReleaseComObject(workbook);
		   System::Runtime::InteropServices::Marshal::ReleaseComObject(excelApp);
	   }

	 

private: System::Void report_Click(System::Object^ sender, System::EventArgs^ e) {
	ExportToExcel();
}
};

};




