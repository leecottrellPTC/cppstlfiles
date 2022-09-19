package com.leecottrell.simpleclient;

import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
/**
 * Hello world!
 *
 */
public class App 
{
    final static CloseableHttpClient httpClient = HttpClients.createDefault();

    public static void main( String[] args ) 
    {
        
        try{
            HttpGet request = new HttpGet("http://api.weatherapi.com/v1/current.json?key=2faaacd2691c4d0eb52140229202810&q=Pittsburgh");
            CloseableHttpResponse response = httpClient.execute(request);
            HttpEntity entity = response.getEntity();
            System.out.println(EntityUtils.toString(entity));
        }
        catch(Exception ex){
            System.out.println("You have an error, read the error message and fix it");
            System.out.println(ex.toString());
            System.exit(1);
        }

    }
}
