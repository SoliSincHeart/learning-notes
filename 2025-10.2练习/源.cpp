using Godot;
using System;

public partial class InputText : Node
{
	public override void _Ready()
	{
		//Input.MouseMode = Input.MouseModeEnum.Hidden;
	}

	public override void _Process(double delta)
	{
		if (Input.IsKeyPressed(Key.B))
		{
			GD.Print("������B");
		}
		if (Input.IsActionJustPressed("��Ծ"))
		{
			GD.Print("��������Ծ");
		}
		if (Input.IsActionPressed("��Ծ"))
		{
			GD.Print("������Ծ");
		}
		if (Input.IsActionJustReleased("��Ծ"))
		{
			GD.Print("������Ծ");
		}
		//float s = Input.GetActionStrength("��Ծ");
		//GD.Print(s);
		//float horizontal = Input.GetAxis("��", "��");
		//GD.Print(horizontal);
		Vector2 dir = Input.GetVector("��", "��", "��", "��");
		GD.Print(dir);
	}

	public override void _Input(InputEvent @event)
	{
		base._Input(@event);
		if (@event is InputEventKey)
		{
			var key = @event as InputEventKey;
			if (key.Keycode == Key.V)
			{
				if (key.IsEcho())
					GD.Print("����v");
				else if (key.IsPressed())
				{
					GD.Print("����v");
				}
				else
				{
					GD.Print("̧��v");
				}
			}
		}
		if (@event is InputEventMouse)
		{
			var mouse = @event as InputEventMouse;
			if (mouse.IsPressed())
			{
				GD.Print(mouse.Position);
				GD.Print(mouse.ButtonMask);
			}
		}
	}
}
