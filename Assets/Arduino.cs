using System.Collections;
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Arduino : MonoBehaviour
{
    SerialPort serialPort = new SerialPort("COM3", 9600);
    float roomTemp;
    int fanSpeed;
    [SerializeField] TMP_Text temp;
    [SerializeField] TMP_Text speed;
    void Start()
    {
        serialPort.Open();
    }


    void Update()
    {
        if (serialPort.IsOpen)
        {
            string[] data = serialPort.ReadLine().Split();

            temp.text = data[0] + " C";
            speed.text = "x " + data[1];

        }
    }
}
