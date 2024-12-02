#pragma once

namespace alexcrevork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для home
	/// </summary>
	public ref class home : public System::Windows::Forms::Form
	{
	public:
		home(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::ListView^ listClient;



	private: System::Windows::Forms::TextBox^ inputClientName;
	private: System::Windows::Forms::TextBox^ inputClienNamber;


	private: System::Windows::Forms::TextBox^ inputBludoName;
	private: System::Windows::Forms::TextBox^ inputBludoPrice;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListView^ listBludo;

	private: System::Windows::Forms::ColumnHeader^ bludoName;
	private: System::Windows::Forms::ColumnHeader^ bludoCena;
	private: System::Windows::Forms::ColumnHeader^ nameClient;
	private: System::Windows::Forms::ColumnHeader^ numberClient;
	private: System::Windows::Forms::ListView^ zakaz;





	private: System::Windows::Forms::ColumnHeader^ clientName;
	private: System::Windows::Forms::ColumnHeader^ eatItog;
	private: System::Windows::Forms::ColumnHeader^ oplata;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->listClient = (gcnew System::Windows::Forms::ListView());
			this->nameClient = (gcnew System::Windows::Forms::ColumnHeader());
			this->numberClient = (gcnew System::Windows::Forms::ColumnHeader());
			this->inputClientName = (gcnew System::Windows::Forms::TextBox());
			this->inputClienNamber = (gcnew System::Windows::Forms::TextBox());
			this->inputBludoName = (gcnew System::Windows::Forms::TextBox());
			this->inputBludoPrice = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBludo = (gcnew System::Windows::Forms::ListView());
			this->bludoName = (gcnew System::Windows::Forms::ColumnHeader());
			this->bludoCena = (gcnew System::Windows::Forms::ColumnHeader());
			this->zakaz = (gcnew System::Windows::Forms::ListView());
			this->clientName = (gcnew System::Windows::Forms::ColumnHeader());
			this->eatItog = (gcnew System::Windows::Forms::ColumnHeader());
			this->oplata = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// createBludo
			// 
			this->createBludo->Location = System::Drawing::Point(253, 116);
			this->createBludo->Name = L"createBludo";
			this->createBludo->Size = System::Drawing::Size(109, 32);
			this->createBludo->TabIndex = 0;
			this->createBludo->Text = L"Добавить блюдо";
			this->createBludo->UseVisualStyleBackColor = true;
			this->createBludo->Click += gcnew System::EventHandler(this, &home::createBludo_Click);
			// 
			// createClient
			// 
			this->createClient->Location = System::Drawing::Point(454, 116);
			this->createClient->Name = L"createClient";
			this->createClient->Size = System::Drawing::Size(109, 32);
			this->createClient->TabIndex = 1;
			this->createClient->Text = L"Добавить клиента";
			this->createClient->UseVisualStyleBackColor = true;
			this->createClient->Click += gcnew System::EventHandler(this, &home::createClient_Click);
			// 
			// createZakaz
			// 
			this->createZakaz->Location = System::Drawing::Point(354, 250);
			this->createZakaz->Name = L"createZakaz";
			this->createZakaz->Size = System::Drawing::Size(122, 43);
			this->createZakaz->TabIndex = 2;
			this->createZakaz->Text = L"Создать заказ";
			this->createZakaz->UseVisualStyleBackColor = true;
			this->createZakaz->Click += gcnew System::EventHandler(this, &home::createZakaz_Click);
			// 
			// listClient
			// 
			this->listClient->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->listClient->CheckBoxes = true;
			this->listClient->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->nameClient, this->numberClient });
			this->listClient->FullRowSelect = true;
			this->listClient->GridLines = true;
			this->listClient->HideSelection = false;
			this->listClient->Location = System::Drawing::Point(13, 177);
			this->listClient->Name = L"listClient";
			this->listClient->Size = System::Drawing::Size(203, 159);
			this->listClient->TabIndex = 4;
			this->listClient->Tag = L"Список клиентов";
			this->listClient->UseCompatibleStateImageBehavior = false;
			this->listClient->View = System::Windows::Forms::View::Details;			
			// 
			// nameClient
			// 
			this->nameClient->Tag = L"Имя клиента";
			this->nameClient->Text = L"Имя клиента";
			this->nameClient->Width = 135;
			// 
			// numberClient
			// 
			this->numberClient->Tag = L"Номер Клиента";
			this->numberClient->Text = L"Номер";
			this->numberClient->Width = 63;
			// 
			// inputClientName
			// 
			this->inputClientName->Location = System::Drawing::Point(441, 25);
			this->inputClientName->Name = L"inputClientName";
			this->inputClientName->Size = System::Drawing::Size(130, 20);
			this->inputClientName->TabIndex = 5;
			// 
			// inputClienNamber
			// 
			this->inputClienNamber->Location = System::Drawing::Point(441, 81);
			this->inputClienNamber->Name = L"inputClienNamber";
			this->inputClienNamber->Size = System::Drawing::Size(130, 20);
			this->inputClienNamber->TabIndex = 6;
			
			// 
			// inputBludoName
			// 
			this->inputBludoName->Location = System::Drawing::Point(240, 25);
			this->inputBludoName->Name = L"inputBludoName";
			this->inputBludoName->Size = System::Drawing::Size(141, 20);
			this->inputBludoName->TabIndex = 7;
			// 
			// inputBludoPrice
			// 
			this->inputBludoPrice->Location = System::Drawing::Point(240, 81);
			this->inputBludoPrice->Name = L"inputBludoPrice";
			this->inputBludoPrice->Size = System::Drawing::Size(141, 20);
			this->inputBludoPrice->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(252, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Стоимость Блюда";
			
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(252, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Название блюда";
			
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(451, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Введите Имя Клиента";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(451, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Введите Номер Клиента";
			// 
			// listBludo
			// 
			this->listBludo->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->listBludo->CheckBoxes = true;
			this->listBludo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->bludoName, this->bludoCena });
			this->listBludo->FullRowSelect = true;
			this->listBludo->GridLines = true;
			this->listBludo->HideSelection = false;
			this->listBludo->Location = System::Drawing::Point(13, 9);
			this->listBludo->Name = L"listBludo";
			this->listBludo->Size = System::Drawing::Size(203, 159);
			this->listBludo->TabIndex = 2;
			this->listBludo->Tag = L"меню";
			this->listBludo->UseCompatibleStateImageBehavior = false;
			this->listBludo->View = System::Windows::Forms::View::Details;
			// 
			// bludoName
			// 
			this->bludoName->Tag = L"Название блюда";
			this->bludoName->Text = L"Блюдо";
			this->bludoName->Width = 129;
			// 
			// bludoCena
			// 
			this->bludoCena->Tag = L"Стоимость ";
			this->bludoCena->Text = L"Стоимость";
			this->bludoCena->Width = 69;
			// 
			// zakaz
			// 
			this->zakaz->BackColor = System::Drawing::SystemColors::MenuBar;
			this->zakaz->BackgroundImageTiled = true;
			this->zakaz->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->clientName, this->eatItog,
					this->oplata
			});
			this->zakaz->FullRowSelect = true;
			this->zakaz->GridLines = true;
			this->zakaz->HideSelection = false;
			this->zakaz->Location = System::Drawing::Point(1, 374);
			this->zakaz->Name = L"zakaz";
			this->zakaz->Size = System::Drawing::Size(664, 279);
			this->zakaz->TabIndex = 13;
			this->zakaz->Tag = L"Заказы";
			this->zakaz->UseCompatibleStateImageBehavior = false;
			this->zakaz->View = System::Windows::Forms::View::Details;
			// 
			// clientName
			// 
			this->clientName->Tag = L"Клиент";
			this->clientName->Text = L"Клиент";
			this->clientName->Width = 243;
			// 
			// eatItog
			// 
			this->eatItog->Tag = L"Блюдо";
			this->eatItog->Text = L"Блюдо";
			this->eatItog->Width = 207;
			// 
			// oplata
			// 
			this->oplata->Tag = L"Итого к оплате";
			this->oplata->Text = L"Итого к оплате";
			this->oplata->Width = 162;
			// 
			// home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 655);
			this->Controls->Add(this->zakaz);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inputBludoPrice);
			this->Controls->Add(this->inputBludoName);
			this->Controls->Add(this->inputClienNamber);
			this->Controls->Add(this->inputClientName);
			this->Controls->Add(this->listClient);
			this->Controls->Add(this->listBludo);
			this->Controls->Add(this->createZakaz);
			this->Controls->Add(this->createClient);
			this->Controls->Add(this->createBludo);
			this->Name = L"home";
			this->Text = L"home";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void createBludo_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!String::IsNullOrEmpty(inputBludoName->Text) && !String::IsNullOrEmpty(inputBludoPrice->Text)) {
		ListViewItem^ item = gcnew ListViewItem(inputBludoName->Text);
		item->SubItems->Add(inputBludoPrice->Text);
		listBludo->Items->Add(item);

		// Очистка полей ввода
		inputBludoName->Clear();
		inputBludoPrice->Clear();
	}
	else {
		MessageBox::Show("Введите название и цену блюда", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

private: System::Void createClient_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!String::IsNullOrEmpty(inputClientName->Text) && !String::IsNullOrEmpty(inputClienNamber->Text)) {
		ListViewItem^ item = gcnew ListViewItem(inputClientName->Text);
		item->SubItems->Add(inputClienNamber->Text);
		listClient->Items->Add(item);

		// Очистка полей ввода
		inputClientName->Clear();
		inputClienNamber->Clear();
	}
	else {
		MessageBox::Show("Введите имя и номер клиента", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}



private: System::Void createZakaz_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверяем, выбран ли клиент
	if (listClient->SelectedItems->Count > 0 && listBludo->CheckedItems->Count > 0) {
		// Получаем имя клиента
		String^ clientName = listClient->SelectedItems[0]->SubItems[0]->Text;

		// Формируем строку с блюдами и рассчитываем итоговую сумму
		String^ dishes = "";
		double total = 0;

		for each (ListViewItem ^ bludoItem in listBludo->CheckedItems) {
			dishes += bludoItem->Text + "; ";

			// Парсим стоимость блюда
			try {
				String^ priceText = bludoItem->SubItems[1]->Text;
				double price = Convert::ToDouble(priceText);
				total += price;
			}
			catch (FormatException^ ex) {
				MessageBox::Show("Некорректный формат стоимости блюда: " + bludoItem->Text, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// Добавляем заказ в таблицу заказов
		ListViewItem^ zakazItem = gcnew ListViewItem(clientName);
		zakazItem->SubItems->Add(dishes);
		zakazItem->SubItems->Add(total.ToString("F2")); // Форматируем как число с двумя знаками после запятой
		zakaz->Items->Add(zakazItem);

		// Очистка выбора блюд
		for each (ListViewItem ^ bludoItem in listBludo->CheckedItems) {
			bludoItem->Checked = false;
		}
	}
	else {
		MessageBox::Show("Выберите клиента и хотя бы одно блюдо", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

};
}
