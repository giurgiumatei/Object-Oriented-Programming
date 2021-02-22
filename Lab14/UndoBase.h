#pragma once


class UndoBaseClass
{
public:

	UndoBaseClass();
	virtual void execute_undo() = 0;

};

