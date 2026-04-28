using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Web.Http;
using Newtonsoft.Json.Linq;

namespace CharacterRandomizerServer.Controllers
{
    public class AvatarController : ApiController
    {
        // GET api/avatar
        public HttpResponseMessage Get()
        {
            Random rnd = new Random();
            string json = Newtonsoft.Json.JsonConvert.SerializeObject(new
            {
                Succeed = true,
                SkinColorInt = rnd.Next(0, 3),
                UpperBodyInt = rnd.Next(0, 4),
                LowerBodyInt = rnd.Next(0, 4),
                EyesColorInt = rnd.Next(0, 4),
                HairStyleInt = rnd.Next(0, 4),
                HairColorInt = rnd.Next(0, 6),
                HandsInt = rnd.Next(0, 2),
                FeetInt = rnd.Next(0, 2),
                BodyTypeFloat = rnd.NextDouble()
            });
            return new HttpResponseMessage(HttpStatusCode.OK)
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json")
            };
        }

        // GET api/avatar/5
        public string Get(int id)
        {
            return "value";
        }

        // POST api/avatar
        public void Post([FromBody] string value)
        {
        }

        // PUT api/avatar/5
        public void Put(int id, [FromBody] string value)
        {
        }

        // DELETE api/avatar/5
        public void Delete(int id)
        {
        }

        public class Avatar
        {
            int SkinColorInt;

            public Avatar(int _SkinColorInt)
            {
                SkinColorInt = _SkinColorInt;
            }

        }
    }
}
