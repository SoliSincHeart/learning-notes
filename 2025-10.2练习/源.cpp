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
			GD.Print("按下了B");
		}
		if (Input.IsActionJustPressed("跳跃"))
		{
			GD.Print("按下了跳跃");
		}
		if (Input.IsActionPressed("跳跃"))
		{
			GD.Print("持续跳跃");
		}
		if (Input.IsActionJustReleased("跳跃"))
		{
			GD.Print("结束跳跃");
		}
		//float s = Input.GetActionStrength("跳跃");
		//GD.Print(s);
		//float horizontal = Input.GetAxis("左", "右");
		//GD.Print(horizontal);
		Vector2 dir = Input.GetVector("左", "右", "上", "下");
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
					GD.Print("持续v");
				else if (key.IsPressed())
				{
					GD.Print("按下v");
				}
				else
				{
					GD.Print("抬起v");
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
